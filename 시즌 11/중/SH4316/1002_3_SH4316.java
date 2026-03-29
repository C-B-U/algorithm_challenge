import java.io.*;
import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Stream;

public class Main {

	static Main main;
	static StringBuilder result;
	static boolean debug = true;

	public static void main(String[] args) {
		main = new Main();
		result = new StringBuilder();
		main.input();
		System.out.print(result);
	}
	void input() {
		int n, k, a, b;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String[] str = br.readLine().split(" ");
			n = Integer.parseInt(str[0]);
			k = Integer.parseInt(str[1]);
			a = Integer.parseInt(str[2]);
			b = Integer.parseInt(str[3]);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		output(n, k, a, b);
	}
	void output(int n, int k, int a, int b) {
		int day = 1;
		int level = k;
		int l = n / a + (n%a == 0 ? 0 : 1);

		while (level > 0) {
			if (level >= l) {
				day += l;
				level -= l;
				level += b;
			}
			else {
				day += level;
				level = 0;
			}
		}
		result.append(day-1);
	}
}
