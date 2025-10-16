import java.net.*;
import java.io.*;

public class Server {
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(2001);
        System.out.println("Server is listening...");
        Socket socket = serverSocket.accept();
        System.out.println("Client connected...");
        BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter pw = new PrintWriter(socket.getOutputStream());
        pw.println("Hello Client");
        pw.flush();
        String msg1 = br.readLine();
        System.out.println("Client says: " + msg1);

        BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));

        for(;;) // for sending iterative msg to client
        {
            System.out.println("Enter message to send to client: ");
            String msg = br1.readLine();
            if (msg.equals("quit"))
                break;
            pw.println(msg);
            pw.flush();
            String msg2 = br.readLine();
            System.out.println("Client says: " + msg2);
        }
    }
}