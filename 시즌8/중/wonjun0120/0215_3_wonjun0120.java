import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Math;

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[Math.max(n + 1, 4)];
        dp[1] = 0; dp[2] = 1; dp[3] = 1;

        for(int i = 4; i <= n; i++){
            int min_val = dp[i - 1];
            if(i % 2 == 0){
                min_val = Math.min(dp[i / 2], min_val);
            }
            if(i % 3 == 0){
                min_val = Math.min(dp[i / 3], min_val);
            }
            dp[i] = min_val + 1;
        }


        System.out.println(dp[n]);

    }
}