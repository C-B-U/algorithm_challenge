import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    // 문제에서 요구한 나머지 연산 값
    static final int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());

        if (N == 1) {
            System.out.println(0);
            return;
        }

        long[] dp = new long[3];
 
        dp[1] = 1; 
        dp[2] = 1; 
      
        for (int i = 2; i < N; i++) {
            long prev0 = dp[0];
            long prev1 = dp[1];
            long prev2 = dp[2];
            
            dp[0] = (prev1 + prev2) % MOD; 
            dp[1] = (prev0 + prev2) % MOD;
            dp[2] = (prev0 + prev1) % MOD;
        }
        System.out.println(dp[1]);
    }
}
