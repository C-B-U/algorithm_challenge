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
	}
	void input() {
		int a, b, n;
		int[] x = new int[10];
		int[] y = new int[10];
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String[] str = br.readLine().split(" ");
			n = Integer.parseInt(str[0]);
			a = Integer.parseInt(str[1]);
			b = Integer.parseInt(str[2]);
			for (int i = 0; i < 10; i++) {
				str = br.readLine().split(" ");
				x[i] = Integer.parseInt(str[0]);
				y[i] = Integer.parseInt(str[1]);
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}

		output(n, a, b, x, y);
	}
	void output(int n, int a, int b, int[] x, int[] y) {
		int t = 8-n;

		for (int i = 0; i < t; i++) {
			int c = x[i];
			a += x[i]*3;
			b += x[i]*3;

			if (y[i] < 6-c) {
				b += y[i]*3;
			} else {
				b += (6-c)*3;
			}
		}
		if (a >= 66 && b >= 130) {
			System.out.println("Nice");
		} else {
			System.out.println("Nae ga wae");
		}
	}
}
