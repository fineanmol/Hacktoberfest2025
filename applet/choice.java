import java.awt.*;
import javax.swing.*;

public class choice extends JFrame {
    public choice() {
        setTitle("Choice");
        setLayout(new FlowLayout());

        // Independent checkboxes
        Checkbox c1 = new Checkbox("Bengali", true);
        Checkbox c2 = new Checkbox("English");
        Checkbox c3 = new Checkbox("Hindi");

        // Mutually exclusive checkboxes (radio buttons style)
        CheckboxGroup cbg = new CheckboxGroup();
        Checkbox c4 = new Checkbox("MCA", cbg, true);
        Checkbox c5 = new Checkbox("M.Sc", cbg, false);
        Checkbox c6 = new Checkbox("M.E", cbg, false);

        // Dropdown menu (Choice)
        Choice color = new Choice();
        color.add("red");
        color.add("green");
        color.add("blue");

        // Scrollable multi-select list
        List icecream = new List(3, true);
        icecream.add("chocolate");
        icecream.add("vanilla");
        icecream.add("strawberry");
        icecream.add("orange");
        icecream.add("mango");

        // Add components to frame
        add(c1); add(c2); add(c3);
        add(c4); add(c5); add(c6);
        add(color); add(icecream);

        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        // Run on Event Dispatch Thread (best practice for Swing)
        SwingUtilities.invokeLater(() -> new choice());
    }
}
