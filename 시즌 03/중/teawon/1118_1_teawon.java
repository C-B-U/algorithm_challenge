import java.util.*;
import java.io.*;

/*
 * 문제 주소 :  https://www.acmicpc.net/problem/15681
 * 85636KB | 928ms
 **/
public class Main {

    static int[] count;
    static ArrayList<Integer>[] tree;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();

        int N = Integer.parseInt(st.nextToken()); // 트리의 정점 수
        int R = Integer.parseInt(st.nextToken()); // 루트 번호
        int Q = Integer.parseInt(st.nextToken()); // 쿼리 번호

        count = new int[N + 1]; // 각 노드에 대한 쿼리 답

        tree = new ArrayList[N + 1];

        for (int i = 1; i < N + 1; i++) {
            tree[i] = new ArrayList<>(); // 각 노드에 대해 연결되어있는 노드의 관계를 ArrayList로 표현
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            tree[left].add(right);
            tree[right].add(left);
        }
        cal_dfs(R, -1);

        for (int i = 0; i < Q; i++) {
            int node = Integer.parseInt(br.readLine());
            sb.append(count[node] + "\n");
        }
        System.out.print(sb);
    }

    static void cal_dfs(int node, int parant) {
        count[node] = 1;
        for (int i = 0; i < tree[node].size(); i++) {
            int child = tree[node].get(i);
            if (child == parant)
                continue;
            cal_dfs(child, node);
            count[node] += count[child];
        }

    }

}