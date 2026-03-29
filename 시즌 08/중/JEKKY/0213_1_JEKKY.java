package Main;
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Fibonacci F = new Fibonacci();
		F.play();
	}
}
class Fibonacci {
	static Integer[][] dp = new Integer[41][2];
	public Fibonacci() {}
	public void play() {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[1][0] = 0;
		dp[1][1] = 1;
		for(int i = 0; i < N; i++) {
			int T = input.nextInt();
			fibonacci(T);
			System.out.println(dp[T][0] + " " + dp[T][1]);
		}
		input.close();
	}
	static Integer[] fibonacci(int N) {
		if(dp[N][0] == null || dp[N][1] == null) {
			dp[N][0] = fibonacci(N - 1)[0] + fibonacci(N - 2)[0];
			dp[N][1] = fibonacci(N - 1)[1] + fibonacci(N - 2)[1];
		}
		return dp[N];
	}
}