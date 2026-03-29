import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
	public static void main(String[] args) {
		input();
		Arrays.stream(input().split(" "))
				.filter(v -> !v.equals("") && !v.equals(" "))
				.mapToInt(Integer::parseInt)
				.forEach(value -> {

					if (value > max)
						max = value;
					if (value < min)
						min = value;
				});
		System.out.println(min + " " + max);
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
