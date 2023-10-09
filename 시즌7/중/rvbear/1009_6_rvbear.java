import java.io.*;
import java.util.*;

public class Main {
    static int t, m, n, k;                  // Testcase 수, 가로, 세로, 연결 개수
    static int[][] map;                     // 배추밭 정보 저장 배열
    static boolean[][] visit;               // 방문 여부
    static int count;                       // 필요한 배추흰지렁이 수
    static int[] dx = {-1, 1, 0, 0};        // 움직이는 x 좌표
    static int[] dy = {0, 0, -1, 1};        // 움직이는 y 좌표
    static void dfs(int x, int y) {         // dfs 탐색 시작
        visit[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx >= 0 && mx < m && my >= 0 && my < n && !visit[mx][my] && map[mx][my] == 1) {
                dfs(mx, my);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));           // 버퍼 스트림을 통해 입력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));         // 버퍼 스트림을 통해 출력
        t = Integer.parseInt(br.readLine());            // 테스트 케이스 개수 입력
        for(int i = 0; i < t; i++) {
            count = 0;                                  // 변수 초기화
            StringTokenizer stk = new StringTokenizer(br.readLine());
            m = Integer.parseInt(stk.nextToken());      // 가로 길이 입력
            n = Integer.parseInt(stk.nextToken());      // 세로 길이 입력
            map = new int[m][n];                        // 배열 정보 초기화
            visit = new boolean[m][n];                  // 배열 정보 초기화

            k = Integer.parseInt(stk.nextToken());      // 연결 개수 입력
            for(int j = 0; j < k; j++) {
                stk = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(stk.nextToken());
                int y = Integer.parseInt(stk.nextToken());
                map[x][y] = 1;                           // 배추밭 배열에 저장
            }

            for(int r = 0; r < m; r++) {                 // 탐색 시작
                for(int s = 0; s < n; s++) {
                    if(!visit[r][s] && map[r][s] == 1) {
                        dfs(r, s);
                        count++;                         // 조건에 부합할 때마다 필요한 배추흰지렁이 수 증가
                    }
                }
            }

            bw.write(String.valueOf(count) + "\n");  // 버퍼에 저장
        }

        br.close();             // 입력 버퍼 스트림 닫아줌
        bw.close();             // 출력 버퍼 스트림 닫아줌
    }
}