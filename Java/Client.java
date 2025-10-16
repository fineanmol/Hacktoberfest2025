import java.net.*;
import java.io.*;

public class Client {
    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("localhost", 2001);
        System.out.println("Got connected...");
        BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String msg1 = br.readLine();
        System.out.println("Server says: " + msg1);
        PrintWriter pw = new PrintWriter(socket.getOutputStream());
        pw.println("Hello Server");
        pw.flush();

        BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));

        for(;;) // for sending iterative msg to server
        {
            System.out.println("Enter message to send to server: ");
            String msg = br1.readLine();
            if (msg.equals("quit"))
                break;
            pw.println(msg);
            pw.flush();
            String msg2 = br.readLine();
            System.out.println("Server says: " + msg2);
        }
    }
}