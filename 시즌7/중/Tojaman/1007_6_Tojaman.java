package 유기농배추_1012;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static boolean[][] visit;
    static int[] dx = { 0, -1, 0, 1 };
    static int[] dy = { 1, 0, -1, 0 };
    static int m, n;
    static int[][] napa;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int k;


        // T : 테스트 횟수
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int cnt = 0;
            st = new StringTokenizer(br.readLine(), " ");
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            napa = new int[m][n];
            visit = new boolean[m][n];

            for (int j = 0; j < k; j++) {
                st = new StringTokenizer(br.readLine());
                int tx = Integer.parseInt(st.nextToken());
                int ty = Integer.parseInt(st.nextToken());
                napa[tx][ty] = 1;
            }

            for (int a = 0; a < m; a++)
                for (int b = 0; b < n; b++) {
                    if (!visit[a][b] && napa[a][b] == 1) {
                        dfs(a, b);
                        cnt++;
                    }
                }
            System.out.println(cnt);
        }


    }
    static void dfs(int x, int y) {
        visit[x][y] = true; // 확인한 곳 = true

        for (int i = 0; i < 4; i++) {
            // 상하좌우
            int cx = x + dx[i];
            int cy = y + dy[i];

            // 구간 밖으로 벗어나지 않았고
            if (cx >= 0 && cy >= 0 && cx < m && cy < n) {
                // 방문하지 않았고 && 인접한 곳에 배추가 있다면
                if (!visit[cx][cy] && napa[cx][cy] == 1) {
                    dfs(cx, cy);
                }
            }

        }

    }
}