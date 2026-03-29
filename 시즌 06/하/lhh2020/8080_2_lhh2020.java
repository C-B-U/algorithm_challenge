import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		String[] inputs = inputs(" ");
		int x = Integer.parseInt(inputs[0]);
		int y = Integer.parseInt(inputs[1]);
		int w = Integer.parseInt(inputs[2]);
		int h = Integer.parseInt(inputs[3]);

		int result = x;
		if (result > y) result = y;
		if (result > w - x) result = w - x;
		if (result > h - y) result = h - y;
		System.out.println(result);
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
