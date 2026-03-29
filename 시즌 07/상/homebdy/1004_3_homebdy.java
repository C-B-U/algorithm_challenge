import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String [] args) throws Exception {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] level = new int[n + 1];
        int[] power = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n + 1; i++) {
            level[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n + 1; i++) {
            power[i] = Integer.parseInt(st.nextToken());
        }
        int d = Integer.parseInt(br.readLine());
        int[] dp = new int[d + 1];

        long initial = 0;
        for(int i = 1 ; i <= n ; i++) {
            initial += (long) level[i] * power[i];
            level[i] = Math.min(d, level[i]);
        }

        for (int i = 1; i < n + 1; i++) {
            while (level[i] > 0) {
                for (int j = d; j >= 0; j--) {
                    for (int k = i + 1; k <= n && k + j - i <= d; k++) {
                        dp[k + j - i] = Math.max(dp[k + j - i], dp[j] + power[k] - power[i]);
                    }
                }
                level[i]--;
            }
        }
        System.out.println(initial + dp[d]);
    }
}
