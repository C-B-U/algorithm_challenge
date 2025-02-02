import java.io.*;
import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Supplier;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

	static Main main;
	static StringBuilder result;
	static boolean debug = false;

	public static void main(String[] args) {
		main = new Main();
		result = new StringBuilder();
		main.input();
		System.out.print(result);
	}
	void input() {
		int[] c;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(br.readLine());
			c = new int[n];
			AtomicInteger index = new AtomicInteger(0);
			for (String s : br.readLine().split(" ")) {
				c[index.getAndIncrement()] = Integer.parseInt(s);
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		output(c);
	}
	void output(int[] c) {
		Arrays.sort(c);

		int maxCount = 1;
		int count = 1;
		int t = -1;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == t) {
				count++;
				continue;
			}

			if (count > maxCount) {
				maxCount = count;
			}
			t = c[i];
			count = 1;
		}
		if (count > maxCount) {
			maxCount = count;
		}

		result.append(maxCount);
	}
}




