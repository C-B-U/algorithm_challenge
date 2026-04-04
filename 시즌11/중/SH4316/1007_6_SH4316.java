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
		String input;
		String[] words;
		int n;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			input = br.readLine();
			n = Integer.parseInt(br.readLine());
			words = new String[n];
			for (int i = 0; i < n; i++) {
				words[i] = br.readLine();
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		output(input, words);
	}
	void output(String input, String[] words) {
		int[] differences = new int[input.length()-1];
		for (int i = 0; i < input.length()-1; i++) {
			differences[i] = diff(input.charAt(i), input.charAt(i+1));
		}
		for (String s : words) {
			if (debug) {
				System.out.println(s);
			}
			int v = diff(s.charAt(0), s.charAt(1));

			for (int i = 0; i < input.length()-1; i++) {
				if (differences[i] == v) {

					if (debug) System.out.println("TRUE : " + i);

					boolean br = false;
					for (int j = 0; j < s.length()-1; j++) {
						if (debug) System.out.println("i, j : " + i + " " + j);
						v = diff(s.charAt(j+0), s.charAt(j+1));

						if (differences[i+j] != v) {
							br = true;
							break;
						}
					}
					if (br) continue;

					int diff = diff(input.charAt(i), s.charAt(0));
					for (int j = 0; j < input.length(); j++) {
						int k = ((int)input.charAt(j))+diff;
						if (k > 'z')
							result.append((char)(k-26));
						else
							result.append((char)(k));
					}
					return;
				}
			}
		}
	}
	int diff(char c1, char c2) {
		if (c2 >= c1)
			return (int)c2 - (int)c1;
		else
			return (int)c2 - (int)c1 + 26;
	}
}
