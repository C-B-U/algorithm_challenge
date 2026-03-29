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
		int n, m;
		String[] a;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String[] str = br.readLine().split(" ");
			n = Integer.parseInt(str[0]);
			m = Integer.parseInt(str[1]);
			a = new String[n*3];

			for (int i = 0; i < n*3; i++) {
				a[i] = br.readLine();
			}

		} catch (IOException e) {
			throw new RuntimeException(e);
		}

		output(a, n, m);
	}
	void output(String[] a, int n, int m) {
		if (debug) {
			System.out.println();
		}

		StringBuffer sb;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				sb = new StringBuffer();
				for (int j = 0; j < m; j++) {
					if ((i+j)%2 == 1) {
						if (a[(i-1)*3+2].charAt(j*3+1) == '#') {
							sb.append(".#.");
						} else {
							sb.append("...");
						}
					} else {
						sb.append('.').append(a[(i)*3].charAt(j*3+1)).append('.');
					}
				}
				a[i*3] = sb.toString();
			}

			if (i != n-1) {
				sb = new StringBuffer();
				for (int j = 0; j < m; j++) {
					if ((i+j)%2 == 1) {
						if (a[(i+1)*3].charAt(j*3+1) == '#') {
							sb.append(".#.");
						} else {
							sb.append("...");
						}
					} else {
						sb.append('.').append(a[(i)*3+2].charAt(j*3+1)).append('.');
					}
				}
				a[i*3+2] = sb.toString();
			}


			sb = new StringBuffer();
			sb.append(".#");
			if (i % 2 == 1) sb.append(a[i * 3 + 1].charAt(3));
			else 			sb.append(a[i * 3 + 1].charAt(2));
			for (int j = 1; j < m-1; j++) {
				if ((i+j)%2 == 1) {
					sb.append(a[i*3+1].charAt((j-1)*3+2)).append('#').append(a[i*3+1].charAt((j+1)*3));
				} else {
					sb.append(a[i*3+1].charAt(j*3)).append('#').append(a[i*3+1].charAt(j*3+2));
				}
			}
			if ((i+m-1) % 2 == 1) 	sb.append(a[i*3+1].charAt((m-2)*3+2));
			else 					sb.append(a[i*3+1].charAt((m-1)*3));
			sb.append("#.");
			a[i*3+1] = sb.toString();
		}
		for (int i = 0; i < n*3; i++) {
			System.out.println(a[i]);
		}
	}
}




