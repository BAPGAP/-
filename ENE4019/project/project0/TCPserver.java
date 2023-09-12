import java.io.*;
import java.net.*;

public class TCPserver {
	public static void main(String[] args) throws Exception {
		String clientSentence;
		String capitalizedSentence;
		ServerSocket welcomeSocket = new ServerSocket(8888);
		
		while(true) {
			System.out.println("client waiting...");
			Socket connectionSocket = welcomeSocket.accept();
			System.out.println("client connected!!");

			DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
			BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));

			clientSentence = inFromClient.readLine();
			
			capitalizedSentence = clientSentence.toUpperCase() + '\n';
			
			outToClient.writeBytes(capitalizedSentence);
		}
	}
}
