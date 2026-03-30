import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer>[] graph;
    static boolean isVisited[];
    static int delete;
    static int answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk;

        int n = Integer.parseInt(br.readLine());

        graph = new ArrayList[n + 1];
        isVisited = new boolean[n + 1];
        int[] parent = new int[n + 1];

        for (int i = 0; i < n; i++){
            graph[i] = new ArrayList<Integer>();
        }

        int root = -1;
        stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int p = Integer.parseInt(stk.nextToken());

            if (p == -1) {
                root = i; 
            } else {
                graph[i].add(p);
                graph[p].add(i);
            }
        }

        delete = Integer.parseInt(br.readLine());
        if (delete == root) {
            System.out.println(0);
            return;
        } else dfs(root);

        System.out.println(answer);
    }

    static void dfs(int idx) {
        isVisited[idx] = true;

        int nodes = 0;
        for (int cur : graph[idx]) {
            if (cur != delete && !isVisited[cur]) {
                nodes++;
                dfs(cur);
            }
        }

        if (nodes == 0) {
            answer++; 
        }
    }
}
