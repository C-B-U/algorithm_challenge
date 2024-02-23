import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    static int V, E, sum;
    static int[] parent;
    static PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
    static class Edge implements Comparable<Edge> {
        int start, end, weight;

        public Edge(int _start, int _end, int _weight) {
            start = _start; end = _end; weight = _weight;
        }

        @Override
        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }
    static int find(int x) {
        if(x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    static void union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot) {
            parent[yRoot] = x;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] temp = br.readLine().split(" ");
        V = Integer.parseInt(temp[0]);
        E = Integer.parseInt(temp[1]);

        for(int i = 0; i < E; i++) {
            temp = br.readLine().split(" ");
            int start = Integer.parseInt(temp[0]);
            int end = Integer.parseInt(temp[1]);
            int weight = Integer.parseInt(temp[2]);
            pq.add(new Edge(start, end, weight));
        }

        parent = new int[V+1];
        for(int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        while(!pq.isEmpty()) {
            Edge e = pq.poll();
            int start = e.start;
            int end = e.end;
            int weight = e.weight;

            if(find(start) == find(end)) {
                continue;
            }

            union(start, end);
            sum += weight;
        }

        System.out.println(sum);
    }
}