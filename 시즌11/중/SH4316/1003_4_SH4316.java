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
		long a, b;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String[] str = br.readLine().split(" ");
			a = Long.parseLong(str[0]);
			b = Long.parseLong(str[1]);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		output(a, b);
	}
	void output(long a, long b) {
		if (a <= 2) {
			a = 4;
			if (b < 4) {
				result.append(0);
				return;
			}
		}
		else if ((a % 2) == 1) {
			a++;
		}
		if ((b % 2) == 1) {
			b--;
		}
//		result.append(a).append(", ").append(b).append('\n');
		result.append((a + b)/2L * ((b - a) / 2L + 1L)).append('\n');
	}
}
