import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class SpaceInvaders extends JPanel implements ActionListener, KeyListener {

    private Timer timer;
    private int playerX = 350;
    private int playerY = 550;
    private boolean leftPressed = false;
    private boolean rightPressed = false;
    private boolean spacePressed = false;

    private ArrayList<Rectangle> bullets;
    private ArrayList<Rectangle> enemies;
    private int enemySpeed = 2;
    private int score = 0;

    public SpaceInvaders() {
        setPreferredSize(new Dimension(800, 600));
        setBackground(Color.black);

        bullets = new ArrayList<>();
        enemies = new ArrayList<>();

        // Spawn initial enemies
        for (int i = 0; i < 8; i++) {
            enemies.add(new Rectangle(80 + i * 80, 50, 40, 30));
        }

        timer = new Timer(15, this);
        timer.start();

        setFocusable(true);
        addKeyListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Move player
        if (leftPressed && playerX > 0) playerX -= 5;
        if (rightPressed && playerX < 750) playerX += 5;

        // Shoot bullets
        if (spacePressed) {
            bullets.add(new Rectangle(playerX + 18, playerY, 5, 10));
            spacePressed = false; // single shot per press
        }

        // Move bullets upward
        Iterator<Rectangle> bulletIt = bullets.iterator();
        while (bulletIt.hasNext()) {
            Rectangle bullet = bulletIt.next();
            bullet.y -= 10;
            if (bullet.y < 0) bulletIt.remove();
        }

        // Move enemies downward slowly
        for (Rectangle enemy : enemies) {
            enemy.y += enemySpeed / 2;
        }

        // Check bullet-enemy collisions
        bulletIt = bullets.iterator();
        while (bulletIt.hasNext()) {
            Rectangle bullet = bulletIt.next();
            Iterator<Rectangle> enemyIt = enemies.iterator();
            while (enemyIt.hasNext()) {
                Rectangle enemy = enemyIt.next();
                if (bullet.intersects(enemy)) {
                    bulletIt.remove();
                    enemyIt.remove();
                    score += 10;
                    break;
                }
            }
        }

        // Check if enemies reach bottom
        for (Rectangle enemy : enemies) {
            if (enemy.y >= 550) {
                timer.stop();
                JOptionPane.showMessageDialog(this, "💥 Game Over! Final Score: " + score);
                System.exit(0);
            }
        }

        // Respawn enemies when all are destroyed
        if (enemies.isEmpty()) {
            Random rand = new Random();
            for (int i = 0; i < 8; i++) {
                enemies.add(new Rectangle(80 + i * 80, 50, 40, 30));
            }
            enemySpeed++;
        }

        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        // Draw player (spaceship)
        g.setColor(Color.green);
        g.fillRect(playerX, playerY, 40, 20);

        // Draw bullets
        g.setColor(Color.red);
        for (Rectangle bullet : bullets) {
            g.fillRect(bullet.x, bullet.y, bullet.width, bullet.height);
        }

        // Draw enemies
        g.setColor(Color.cyan);
        for (Rectangle enemy : enemies) {
            g.fillRect(enemy.x, enemy.y, enemy.width, enemy.height);
        }

        // Draw score
        g.setColor(Color.white);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        g.drawString("Score: " + score, 10, 20);
    }

    // Keyboard input handling
    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();
        if (code == KeyEvent.VK_LEFT) leftPressed = true;
        if (code == KeyEvent.VK_RIGHT) rightPressed = true;
        if (code == KeyEvent.VK_SPACE) spacePressed = true;
    }

    @Override
    public void keyReleased(KeyEvent e) {
        int code = e.getKeyCode();
        if (code == KeyEvent.VK_LEFT) leftPressed = false;
        if (code == KeyEvent.VK_RIGHT) rightPressed = false;
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        JFrame frame = new JFrame("👾 Space Invaders");
        SpaceInvaders game = new SpaceInvaders();
        frame.add(game);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
          }
