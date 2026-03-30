package teawon;

import java.util.*;
import java.io.*;
/*
 * 문제 주소 :  https://www.acmicpc.net/problem/2583
 * 16080KB | 152ms
 **/

public class Main {

    public static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

    static boolean[][] map;
    static boolean[][] visited;
    static int N;
    static int M;
    static ArrayList<Integer> result = new ArrayList<>();
    static int[] dy = { -1, 0, 1, 0 }; // 위에부터 시계방향 검색
    static int[] dx = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        map = new boolean[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());

            int left_x = Integer.parseInt(st.nextToken());
            int left_y = Integer.parseInt(st.nextToken());
            int right_x = Integer.parseInt(st.nextToken());
            int right_y = Integer.parseInt(st.nextToken());

            for (int _y = left_y; _y < right_y; _y++) {
                for (int _x = left_x; _x < right_x; _x++) {
                    map[_y][_x] = true;
                }
            }
        }

        int count = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (map[y][x] == false && visited[y][x] == false) {
                    bfs(y, x);
                    count++;
                }

            }
        }

        Collections.sort(result); // 오름차순으로 정렬
        sb.append(count + "\n");

        for (int i = 0; i < count; i++) {
            sb.append(result.get(i) + " ");
        }
        System.out.println(sb);

    }

    public static void bfs(int _y, int _x) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(_x, _y));
        visited[_y][_x] = true;
        int size = 1;

        while (!q.isEmpty()) {
            Node node = q.poll();
            int y = node.getY();
            int x = node.getX();

            for (int d = 0; d < 4; d++) {
                if (x + dx[d] < 0 || x + dx[d] >= M || y + dy[d] < 0 || y + dy[d] >= N
                        || map[y + dy[d]][x + dx[d]] == true || visited[y + dy[d]][x + dx[d]] == true)
                    continue;
                size++;
                visited[y + dy[d]][x + dx[d]] = true;
                q.offer(new Node(x + dx[d], y + dy[d]));
            }
        }
        result.add(size);
    }
}
