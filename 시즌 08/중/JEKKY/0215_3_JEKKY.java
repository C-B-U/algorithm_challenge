package Main;
import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		Problem P = new Problem();
		P.solve();
	}
}
class Problem {
	public Problem() {}
	public void solve() throws IOException {
		Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] dp = new int[1000001];
        dp[2] = 1;
        dp[3] = 1;
        for (int i = 4; i <= n; i++) {
            if (i % 6 == 0) {
                dp[i] = Math.min(dp[i/3], Math.min(dp[i/2], dp[i-1])) + 1;
            } else if (i % 3 == 0) {
                dp[i] = Math.min(dp[i/3], dp[i-1])+1;
            } else if (i % 2 == 0) {
                dp[i] = Math.min(dp[i/2], dp[i-1]) + 1;
            } else {
                dp[i] = dp[i-1] + 1;
            }
        }
        System.out.print(dp[n]);
		input.close();
	}
}