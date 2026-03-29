import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[N][3];

        for(int i = 0; i < N; i++) {
            String[] temp = br.readLine().split(" ");
            dp[i][0] = Integer.parseInt(temp[0]) + (i == 0 ? 0 : Math.min(dp[i-1][1], dp[i-1][2]));
            dp[i][1] = Integer.parseInt(temp[1]) + (i == 0 ? 0 : Math.min(dp[i-1][0], dp[i-1][2]));
            dp[i][2] = Integer.parseInt(temp[2]) + (i == 0 ? 0 : Math.min(dp[i-1][0], dp[i-1][1]));
        }

        System.out.println(Math.min(Math.min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]));
    }
}
