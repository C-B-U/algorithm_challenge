import java.util.*;

public class Main {
    static int[][] graph;
    static boolean[] visited;
    static int n;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int m = sc.nextInt();
        int v = sc.nextInt();
        
        graph = new int[n+1][n+1];
        visited = new boolean[n+1];
        
        for(int i=0; i<m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            graph[x][y] = graph[y][x] = 1;
        }
        
        dfs(v);
        sb.append('\n');
        visited = new boolean[n+1];
        bfs(v);
        
        System.out.print(sb);
    }
    
    static void dfs(int v) {
        visited[v] = true;
        sb.append(v).append(' ');
        
        for(int i=1; i<=n; i++) {
            if(graph[v][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }
    
    static void bfs(int v) {
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        visited[v] = true;
        
        while(!q.isEmpty()) {
            v = q.poll();
            sb.append(v).append(' ');
            
            for(int i=1; i<=n; i++) {
                if(graph[v][i] == 1 && !visited[i]) {
                    q.add(i);
                    visited[i] = true;
                }
            }
        }
    }
}
