import java.io.*;
import java.util.*;

public class Day_10 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int E = Integer.parseInt(br.readLine().trim());

        List<Integer>[] adj = new ArrayList[505];
        for (int i = 0; i < 505; i++) {
            adj[i] = new ArrayList<>();
        }

        int maxNode = 0;
        for (int e = 0; e < E; e++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            maxNode = Math.max(maxNode, Math.max(u, v));
        }

        long totalSum = 0;
        int totalPairs = maxNode * (maxNode - 1); 

        for (int i = 1; i <= maxNode; i++) {
            int[] dist = new int[maxNode + 1];
            Arrays.fill(dist, -1);
            Queue<Integer> queue = new LinkedList<>();

            queue.add(i);
            dist[i] = 0;

            while (!queue.isEmpty()) {
                int curr = queue.poll();

                for (int next : adj[curr]) {
                    if (dist[next] == -1) {
                        dist[next] = dist[curr] + 1;
                        queue.add(next);
                    }
                }
            }

            for (int j = 1; j <= maxNode; j++) {
                if (i != j) {
                    totalSum += dist[j];
                }
            }
        }

        double avg = (double) totalSum / totalPairs;
        System.out.printf("%.3f\n", avg);
    }
}
