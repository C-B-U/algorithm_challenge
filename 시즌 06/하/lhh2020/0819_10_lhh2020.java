import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.IntStream;

public class Main {
	static int count = 0;
	static int max = 0;
	static int sum = 0;
	static BufferedReader br;
	public static void main(String[] args) {
		br = new BufferedReader(new InputStreamReader(System.in));
		input();
		IntStream stream = Arrays.stream(inputs(" ")).mapToInt(Integer::parseInt);
		stream.forEach(v -> {
			sum += v;
			count++;
			if (v > max) {
				max = v;
			}
		});
		System.out.println(sum / (double)count / max * 100);
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
