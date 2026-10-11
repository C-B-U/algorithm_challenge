import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 1. 훈련병의 수 N 입력
        int n = Integer.parseInt(br.readLine().trim());
        
        // 2. 초기 훈련병 배열 입력
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        // 3. 가장 긴 증가하는 부분 수열(LIS) 구하기
        int[] dp = new int[n];
        int maxLis = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = 1; // 자기 자신만으로 수열을 시작할 때의 길이 1
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxLis = Math.max(maxLis, dp[i]);
        }
        
        // 4. 최소 명령 횟수 = 전체 N - LIS 길이
        int result = n - maxLis;
        
        // 5. 결과 출력
        System.out.println(result);
    }
}
