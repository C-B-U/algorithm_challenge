import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		String[] inputs = inputs(" ");
		int[] nc = new int[5];
		for (int i = 0; i < 5; i++) {
			nc[i] = Integer.parseInt(inputs[i]);
		}
		while (!check(nc)) {
			for (int i = 0; i < 4; i++) {
				if (nc[i] > nc[i+1]) {
					int temp = nc[i];
					nc[i] = nc[i+1];
					nc[i+1] = temp;
					print(nc);
				}
			}
		}
	}
	public static void print(int[] values) {
		System.out.println(values[0] + " " + values[1] + " " + values[2] + " " + values[3] + " " + values[4]);
	}
	public static boolean check(int[] values) {
		int target = -1;
		for (int i = 0; i < 5; i++) {
			if (values[i] > target) {
				target = values[i];
				continue;
			}
			return false;
		}
		return true;
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
