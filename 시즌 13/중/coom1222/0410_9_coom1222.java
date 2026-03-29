import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int[][] arr = new int[N + 1][2];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken()) + arr[i - 1][0]; // 노래
            arr[i][1] = Integer.parseInt(st.nextToken()) + arr[i - 1][1]; // 다운로드
        }
        int idx = N;
        int ans = 0;
        while (idx > 0) {
            ans = Math.max(ans, arr[idx][1] - arr[idx - 1][0]);
            idx--;
        }
        System.out.println(ans);
    }
}
출처: https://pingu0130.tistory.com/51 [전자펭귄 핑구:티스토리]
