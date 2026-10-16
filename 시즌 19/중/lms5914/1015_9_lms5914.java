import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Day_09 {
    private static int N;
    private static int count = 0;
    private static boolean[] width;
    private static boolean[] diag1;
    private static boolean[] diag2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        width = new boolean[N];
        diag1 = new boolean[2 * N - 1];
        diag2 = new boolean[2 * N - 1];

        dfs(0);
        System.out.println(count);
    }

    private static void dfs(int row) {
        if (row == N) {
            count++;
            return;
        }

        for (int col = 0; col < N; col++) {
            if (!width[col] && !diag1[row + col] && !diag2[row - col + N - 1]) {
                width[col] = true;
                diag1[row + col] = true;
                diag2[row - col + N - 1] = true;

                dfs(row + 1);

                width[col] = false;
                diag1[row + col] = false;
                diag2[row - col + N - 1] = false;
            }
        }
    }
}
