import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int n, m;
    static int[] set;
    static int find(int num) {
        if(set[num] == num) {
            return num;
        }
        return set[num] = find(set[num]);
    }
    static void union(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x < y) {
            set[y] = x;
        } else {
            set[x] = y;
        }
    }
    static boolean check(int a, int b) {
        int x = find(a);
        int y = find(b);
        return x == y;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stb = new StringBuilder();
        String[] temp = br.readLine().split(" ");

        n = Integer.parseInt(temp[0]);
        m = Integer.parseInt(temp[1]);

        set = new int[n+1];

        for(int i = 0; i <= n; i++) {
            set[i] = i;
        }

        for(int i = 0; i < m; i++) {
            temp = br.readLine().split(" ");
            int a = Integer.parseInt(temp[1]);
            int b = Integer.parseInt(temp[2]);

            if(Integer.parseInt(temp[0]) == 0) {
                union(a, b);
            } else {
                stb.append(check(a, b) ? "YES" : "NO").append("\n");
            }
        }

        System.out.print(stb);
    }
}