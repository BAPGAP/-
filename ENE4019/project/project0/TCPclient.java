import java.io.*;
import java.net.*;
public class TCPclient {

	public static void main(String[] args) throws Exception{
		String sentence;
		String modifiedSentence;
		String tmp;
		
		BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
		
		Socket clientSocket = new Socket("192.168.56.1", 8888);
		
		DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

		BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

		sentence = inFromUser.readLine();

		outToServer.writeBytes(sentence + '\n');

		modifiedSentence = inFromServer.readLine();
		System.out.println("FROM SERVER: " + modifiedSentence);	
		
		clientSocket.close();
	}
}
