import java.util.*;
import java.io.*;

/*
 * 문제 주소 :  https://www.acmicpc.net/problem/7569
 * 688ms
 * 
*/

public class Main {

    public static int[] dh = { 0, 0, 0, 0, 1, -1 };
    public static int[] dy = { -1, 0, 0, 1, 0, 0 };
    public static int[] dx = { 0, -1, 1, 0, 0, 0 };

    public static class Tomato {
        int x;
        int y;
        int h;

        public Tomato(int h, int y, int x) {
            this.y = y;
            this.x = x;
            this.h = h;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public int getH() {
            return h;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();

        int M = Integer.parseInt(st.nextToken()); // 열
        int N = Integer.parseInt(st.nextToken()); // 행
        int H = Integer.parseInt(st.nextToken()); // 높이

        int[][][] tomato = new int[H][N][M];
        // 0 : 토마토
        // -1 : 빈벽
        // 1 : 익은 토마토

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < M; k++) {
                    tomato[i][j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }

        Queue<Tomato> q = new LinkedList<>();

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (tomato[i][j][k] == 1) {
                        q.add(new Tomato(i, j, k));
                    }
                }

            }
        }

        while (!q.isEmpty()) {
            Tomato data = q.poll();
            int y = data.getY();
            int x = data.getX();
            int h = data.getH();

            for (int d = 0; d < 6; d++) {
                if (x + dx[d] < 0 || x + dx[d] >= M || y + dy[d] < 0 || y + dy[d] >= N || h + dh[d] >= H
                        || h + dh[d] < 0 || tomato[h + dh[d]][y + dy[d]][x + dx[d]] != 0)
                    continue;
                tomato[h + dh[d]][y + dy[d]][x + dx[d]] = tomato[h][y][x] + 1;
                q.offer(new Tomato(h + dh[d], y + dy[d], x + dx[d]));
            }
        }
        int day = 0;
        boolean flag = false;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (tomato[i][j][k] == 0) {
                        day = 0;
                        flag = true;
                    }
                    if (flag)
                        break;
                    day = Math.max(day, tomato[i][j][k]);
                }
            }

        }

        System.out.println(day - 1);

    }
}