import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static BufferedReader br;
	public static void main(String[] args) {
		br = new BufferedReader(new InputStreamReader(System.in));
		int[] values = Arrays.stream(inputs(" ")).mapToInt(Integer::parseInt).toArray();
		int a = values[0];
		int b = values[1];
		int c = values[2];

		if (b >= c) {
			System.out.println(-1);
			return;
		}

		int count = 0;
		int sum = 0;

		while (true) {
			sum += c-b;
			count++;
			if (sum > a) {
				break;
			}
		}
		System.out.println(count);
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
