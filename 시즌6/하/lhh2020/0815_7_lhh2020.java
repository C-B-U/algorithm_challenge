import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static BufferedReader br;
	public static void main(String[] args) {
		br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			int count = 0;
			String input = input();
			if (input == null)
				continue;
			if (input.equals("#"))
				break;
			input = input.toLowerCase();
			for (int i = 2; i < input.length(); i++) {
				if (input.charAt(0) == input.charAt(i)) {
					count++;
				}
			}
			System.out.println(input.charAt(0) + " " + count);
		}
	}
	public static String[] inputs(String regex) {
		try {
			return br.readLine().split(regex);
		} catch (IOException e) {
		}
		return null;
	}
	public static String input() {
		try {
			return br.readLine();
		} catch (IOException e) {
		}
		return null;
	}
}
