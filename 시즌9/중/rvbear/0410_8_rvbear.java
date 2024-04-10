import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int[][] map;
    static Set<String> set;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static void dfs(int x, int y, String num, int depth) {
        if(depth == 6) {
            set.add(num);
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && 0 <= ny && nx < 5 && ny < 5) {
                dfs(nx, ny, num + map[nx][ny], depth + 1);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        map = new int[5][5];
        set = new HashSet<>();

        for(int i = 0; i < 5; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            for(int j = 0; j < 5; j++) {
                int value = Integer.parseInt(stk.nextToken());
                map[i][j] = value;
            }
        }

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                dfs(i, j, "", 0);
            }
        }

        System.out.println(set.size());
    }
}
