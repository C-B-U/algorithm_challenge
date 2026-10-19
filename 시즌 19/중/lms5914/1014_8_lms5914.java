import java.io.*;
import java.util.*;

public class Day_08 {
    static int[] dx = {1, -1, 0, 0, 0, 0};
    static int[] dy = {0, 0, 1, -1, 0, 0};
    static int[] dz = {0, 0, 0, 0, 1, -1};

    static class Point {
        int z, y, x;
        Point(int z, int y, int x) {
            this.z = z;
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());

        int[][][] box = new int[H][N][M];
        Queue<Point> queue = new LinkedList<>();
        int unripeCount = 0;

        for (int h = 0; h < H; h++) {
            for (int n = 0; n < N; n++) {
                st = new StringTokenizer(br.readLine());
                for (int m = 0; m < M; m++) {
                    box[h][n][m] = Integer.parseInt(st.nextToken());
                    if (box[h][n][m] == 1) {
                        queue.offer(new Point(h, n, m));
                    } else if (box[h][n][m] == 0) {
                        unripeCount++;
                    }
                }
            }
        }

        if (unripeCount == 0) {
            System.out.println(0);
            return;
        }

        int days = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean spread = false;

            for (int i = 0; i < size; i++) {
                Point current = queue.poll();

                for (int dir = 0; dir < 6; dir++) {
                    int nz = current.z + dz[dir];
                    int ny = current.y + dy[dir];
                    int nx = current.x + dx[dir];

                    if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
                        if (box[nz][ny][nx] == 0) {
                            box[nz][ny][nx] = 1;
                            unripeCount--;
                            queue.offer(new Point(nz, ny, nx));
                            spread = true;
                        }
                    }
                }
            }

            if (spread) {
                days++;
            }
        }

        if (unripeCount == 0) {
            System.out.println(days);
        } else {
            System.out.println(-1);
        }
    }
}
