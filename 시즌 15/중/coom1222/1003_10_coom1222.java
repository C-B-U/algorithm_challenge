import java.util.*;
import java.io.*;

public class Main {
    static int TC, N, M;
    static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        TC = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= TC; tc++) {
            sb.append("Scenario " + tc + ":\\n");
            N = Integer.parseInt(br.readLine());
            parent = new int[N];

            for (int i = 1; i < N; i++) parent[i] = i;

            M = Integer.parseInt(br.readLine());

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                union(from, to);
            }

            M = Integer.parseInt(br.readLine());

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                if (find(from) == find(to)) sb.append("1\\n");
                else sb.append("0\\n");
            }

            sb.append("\\n");
        }

        System.out.print(sb);
    }

    public static void union(int a, int b){
        int aParent = find(a);
        int bParent = find(b);

        if (aParent < bParent) {
            parent[bParent] = aParent;
        } else if (bParent < aParent) {
            parent[aParent] = bParent;
        }
    }

    public static int find(int t) {
        if (t == parent[t]) return t;
        else return parent[t] = find(parent[t]);
    }
}
