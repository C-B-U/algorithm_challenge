import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static void main(String [] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] speed = new int[n + 1];
        int[] dp = new int[n + 1];
        int[] indegree = new int[n + 1];
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        IntStream.range(1, n + 1).forEach(i -> graph[i] = new ArrayList<>());
        for (int i = 1; i < n + 1; i++) {
            st = new StringTokenizer(br.readLine());
            speed[i] = Integer.parseInt(st.nextToken());
            while (st.hasMoreTokens()) {
                int node = Integer.parseInt(st.nextToken());
                if (node == -1) {
                    break;
                }
                graph[node].add(i);
                indegree[i]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i < n + 1; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            int now = queue.poll();
            for (int j: graph[now]) {
                dp[j] = Math.max(dp[j], dp[now] + speed[now]);
                indegree[j]--;
                if (indegree[j] == 0) {
                    queue.add(j);
                }
            }
            dp[now] += speed[now];
        }

        for (int i = 1; i < n + 1; i++) {
            System.out.println(dp[i]);
        }
    }
}
