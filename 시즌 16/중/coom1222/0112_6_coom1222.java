import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer>[] adj; // 그래프 정보 저장
    static int[] subtreeSize;        // 각 정점을 루트로 하는 서브트리의 크기 저장
    static int N, R, Q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 1. 입력값 처리
        N = Integer.parseInt(st.nextToken()); // 정점의 수
        R = Integer.parseInt(st.nextToken()); // 루트의 번호
        Q = Integer.parseInt(st.nextToken()); // 쿼리의 수

        // 인접 리스트 초기화
        adj = new ArrayList[N + 1];
        subtreeSize = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        // 간선 정보 입력 (트리는 양방향 그래프로 입력됨)
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            adj[v].add(u);
        }

        // 2. DFS를 통해 서브트리 크기 미리 계산 (Pre-computation)
        // 루트(R)부터 시작하며, 부모 노드는 없으므로 -1이나 0(존재하지 않는 노드) 전달
        countSubtreeNodes(R, -1);

        // 3. 쿼리 처리
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            int queryNode = Integer.parseInt(br.readLine());
            sb.append(subtreeSize[queryNode]).append("\n");
        }
        System.out.println(sb);
    }

    // 힌트의 countSubtreeNodes 로직 구현
    // current: 현재 노드, parent: 부모 노드 (재방문 방지용)
    static void countSubtreeNodes(int current, int parent) {
        subtreeSize[current] = 1; // 자기 자신도 포함하므로 1로 시작

        for (int child : adj[current]) {
            // 연결된 노드 중 부모가 아닌 것이 자식 노드임
            if (child != parent) {
                countSubtreeNodes(child, current); // 자식 노드로 이동
                // 자식 노드의 서브트리 크기를 현재 노드에 더함 (Bottom-up 방식)
                subtreeSize[current] += subtreeSize[child];
            }
        }
    }
}
