import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		String input = input();
		int count = 0;
		if (input.charAt(0) == ' ') {
			count--;
		}
		if (input.charAt(input.length() - 1) == ' ') {
			count--;
		}
		for (int i = 0; i < input.length(); i++) {
			if (input.charAt(i) == ' ') {
				count++;
			}
		}
		System.out.println(count+1);
	}
	public static String[] inputs(String regex) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			return br.readLine().split(regex);
		} catch (IOException e) {
		}
		return null;
	}
	public static String input() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			return br.readLine();
		} catch (IOException e) {
		}
		return null;
	}
}
