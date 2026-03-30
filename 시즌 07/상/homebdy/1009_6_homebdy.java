import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class P2515 {

    public static void main(String [] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int[][] picture = new int[n + 1][2];
        int[] dp = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            st = new StringTokenizer(br.readLine());
            picture[i][0] = Integer.parseInt(st.nextToken());
            picture[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(picture, 1, n + 1, (Comparator.comparingInt(o -> o[0])));

        int maxIndex = 1;
        int max = 0;
        for (int i = 1; i < n + 1; i++) {
            while (picture[i][0] - picture[maxIndex][0] >= s) {
                if (max < dp[maxIndex]) {
                    max = Math.max(max, dp[maxIndex]);
                }
                maxIndex++;
            }
            dp[i] = max + picture[i][1];
        }
        System.out.println(Arrays.stream(dp).max().orElse(dp[n]));
    }
}
