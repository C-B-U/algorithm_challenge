package Main;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input;
		String words = "";
		while((input = br.readLine())!=null) {
			words+=input;
		}
		
		int max = 0;
		String total = "";
		for(char i = 97; i < 123; i++) {
			int count = words.length() - words.replace(String.valueOf(i), "").length();
			if (max == count) {
				total +=String.valueOf(i);
			}
			if(max< count) {
				max = count;
				total = String.valueOf(i);
			}
		}
		System.out.println(total);
	}
}