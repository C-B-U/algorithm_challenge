import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    // 문제에서 요구한 모듈러 값
    static final int MOD = 1234567;
    // 인접 리스트 (각 숫자의 이웃들)
    static ArrayList<Integer>[] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 1. 그래프(키패드) 초기화
        initGraph();

        // 2. 테스트 케이스 수 입력
        String line = br.readLine();
        if (line == null) return;
        int T = Integer.parseInt(line.trim());

        StringBuilder sb = new StringBuilder();

        // 3. 각 테스트 케이스 별로 로직 수행
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());
            sb.append(solve(N)).append("\n");
        }
        
        // 결과 출력
        System.out.print(sb);
    }

    // DP를 이용해 비밀번호 개수 계산
    static int solve(int N) {
        // dp[길이][마지막숫자]
        int[][] dp = new int[N + 1][10];

        // 초기값: 길이가 1인 비밀번호는 각 숫자별로 1개씩 존재
        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        }

        // 길이 2부터 N까지 DP 테이블 채우기
        for (int len = 2; len <= N; len++) {
            for (int curr = 0; curr <= 9; curr++) {
                // 현재 숫자(curr)로 오기 위해 이전 숫자(prev)는 curr의 이웃이어야 함
                for (int prev : adj[curr]) {
                    dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % MOD;
                }
            }
        }

        // 길이가 N인 모든 경우의 수 합산
        int total = 0;
        for (int i = 0; i <= 9; i++) {
            total = (total + dp[N][i]) % MOD;
        }
        return total;
    }

    // 키패드 연결 정보 설정
    static void initGraph() {
        adj = new ArrayList[10];
        for (int i = 0; i < 10; i++) {
            adj[i] = new ArrayList<>();
        }

        // 상하좌우 연결 (무방향)
        connect(0, 8);
        connect(1, 2); connect(1, 4);
        connect(2, 3); connect(2, 5);
        connect(3, 6);
        connect(4, 5); connect(4, 7);
        connect(5, 6); connect(5, 8);
        connect(6, 9);
        connect(7, 8);
        connect(8, 9);
    }

    static void connect(int u, int v) {
        adj[u].add(v);
        adj[v].add(u);
    }
}
