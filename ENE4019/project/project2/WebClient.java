import java.io.*;
import java.net.*;
import java.util.Scanner;

public class WebClient {
	
	public static String getWebContentByPost(String urlString,String data,final String charset,int timeout) throws IOException{
		if(urlString == null || urlString.length() == 0) {
			return null;
		}
		urlString = (urlString.startsWith("http://") || urlString.startsWith("https://")) ? urlString : ("http://" + urlString).intern();
		URL url = new URL(urlString);
		HttpURLConnection connection = (HttpURLConnection) url.openConnection();
		
		connection.setDoOutput(true);
		connection.setDoInput(true);
		connection.setRequestMethod("POST");
		
		connection.setUseCaches(false);
		connection.setInstanceFollowRedirects(true);
		
		connection.setRequestProperty("Content-Type","text/xml;charset=UTF-8");
		
		connection.setRequestProperty("User-Agent","2018008559/SANGYOONSHIN/WebClient/ComputerNetwork");
		
		connection.setRequestProperty("Accept", "text/xml");
		connection.setConnectTimeout(timeout);
		connection.connect();
		DataOutputStream out = new DataOutputStream(connection.getOutputStream());
		
		byte[] content = data.getBytes("UTF-8");
		
		out.write(content);
		out.flush();
		out.close();
		
		
		
        BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream(), charset));
        
        String inputLine;
        StringBuffer response = new StringBuffer();
        
        while((inputLine = in.readLine()) != null) {
            response.append(inputLine).append("\r\n");
        }
        
        in.close();
        
        System.out.println(response.toString());
        return null;
	}
	
	public static String getWebContentByGet(String urlString, final String charset,int timeout) throws IOException{
		if(urlString == null || urlString.length() == 0) {
			return null;
		}
		urlString = (urlString.startsWith("http://") || urlString.startsWith("https://")) ? urlString : ("http://" + urlString).intern();
		URL url = new URL(urlString);
		HttpURLConnection conn = (HttpURLConnection) url.openConnection();
		conn.setRequestMethod("GET");
		
		conn.setRequestProperty("User-Agent","Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.2; Trident/4.0; .NET CLR 1.1.4322; .NET CLR 2.0.50727)");
		conn.setRequestProperty("Accept", "text/html");
		conn.setConnectTimeout(timeout);
		try {
			if(conn.getResponseCode() != HttpURLConnection.HTTP_OK) {
				return null;
			}
		} catch(IOException e) {
			e.printStackTrace();
			return  null;
		}
		InputStream input = conn.getInputStream();
		BufferedReader reader = new BufferedReader(new InputStreamReader(input, charset));
		String line = null;
		StringBuffer sb = new StringBuffer();
		while((line = reader.readLine()) != null) {
			sb.append(line).append("\r\n");
		}
		if(reader != null) {
			reader.close();
		}
		if(conn != null) {
			conn.disconnect();
		}
		return sb.toString();
	}
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		String adress = sc.next();
		String number;
		System.out.println(getWebContentByGet(adress,"UTF-8",5000));
		adress = sc.next();
		number = sc.next();
		getWebContentByPost(adress,number,"UTF-8",5000);
		sc.close();
	}
}
