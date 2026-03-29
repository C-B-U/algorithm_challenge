import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int[] dp = new int[N+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for(int i = 0; i < N+1; i++) {
            if(i + 1 <= N) {
                dp[i+1] = Math.min(dp[i] + 1, dp[i+1]);
            }
            if(i + i / 2 <= N) {
                dp[i+i/2] = Math.min(dp[i] + 1, dp[i+i/2]);
            }
        }

        System.out.println(dp[N] <= K ? "minigimbob" : "water");
    }
}