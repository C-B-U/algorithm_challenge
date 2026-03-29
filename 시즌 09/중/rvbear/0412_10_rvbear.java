import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int n, answer;
    static int[] pair = {5, 3, 4, 1, 2, 0};
    static int[][] dice;
    public static void dfs(int top, int sum, int depth) {
        if(depth == n) {
            answer = Math.max(sum, answer);
            return;
        }

        int index = 0;
        for(int i = 0; i < 6; i++) {
            if(dice[depth][i] == top) {
                index = i;
                break;
            }
        }

        int nextTop = pair[index];
        int m = 0;
        for(int i = 0; i < 6; i++) {
            if(i == index || i == nextTop) {
                continue;
            }
            m = Math.max(m, dice[depth][i]);
        }

        dfs(dice[depth][nextTop], sum + m, depth + 1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        answer = 0;
        dice = new int[n][6];

        for(int i = 0; i < n; i++) {
            String[] num = br.readLine().split(" ");
            for(int j = 0; j < 6; j++) {
                dice[i][j] = Integer.parseInt(num[j]);
            }
        }

        for(int i = 0; i < 6; i++) {
            int max = 0;
            for(int j = 0; j < 6; j++) {
                if(j == i || j == pair[i]) {
                    continue;
                }
                max = Math.max(max, dice[0][j]);
            }
            dfs(dice[0][i], max, 1);
        }

        System.out.println(answer);
    }
}