import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class kimhalin_3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[][] board = new int[N][N];
        boolean[][] visited = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = sc.nextInt();
                visited[i][j] = false;
            }
        }
        bfs(board, visited);

        sc.close();

    }
    static void bfs(int[][] board, boolean[][] visited) {
        int len = board.length;
        boolean success = false;
        Queue<int[]> que = new LinkedList<>();
        que.offer(new int[]{0, 0});

        while (!que.isEmpty()) {
            int[] focus = que.poll();
            int r = focus[0], c = focus[1];
            visited[r][c] = true;

            if (board[r][c] == -1) {
                success = true;
                break;
            }

            int bottom = r + board[r][c], right = c + board[r][c];

            if (bottom < len && !visited[bottom][c]) {
                que.offer(new int[]{r + board[r][c], c});
                visited[bottom][c] = true;
            }
            if (right < len && !visited[r][right]) {
                que.add(new int[]{r, c + board[r][c]});
                visited[r][right] = true;
            }
        }

        if (success) {
            System.out.println("HaruHaru");
        } else {
            System.out.println("Hing");
        }
    }
}
