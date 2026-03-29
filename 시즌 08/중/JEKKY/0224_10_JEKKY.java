package Main;
import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		Problem P = new Problem();
		P.solve();
	}
}
class Problem {
	private static class Node implements Comparable<Node>{
        int from;
        int to;
        int weight;
        public Node (int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
        
        @Override
        public int compareTo (Node node) {
            return this.weight - node.weight;
        }
    }
    
    
    static int V, E, parent[];
    
    
    public void solve () throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] input = br.readLine().split(" ");
        V = Integer.parseInt(input[0]+1);
        E = Integer.parseInt(input[1]);
        
        parent = new int[V+1];
        Node[] costs = new Node[E];
        
        for (int i=1; i<=V; i++) parent[i] = i;
        
        for (int i=0; i<E; i++) {
            input = br.readLine().split(" ");
            int from = Integer.parseInt(input[0]);
            int to = Integer.parseInt(input[1]);
            int weight = Integer.parseInt(input[2]);
            costs[i] = new Node(from, to, weight);
        }
        
        Arrays.sort(costs);
        
        int result = 0;
        
        for (Node node : costs) {
            
            int from = node.from;
            int to = node.to;
            int weight = node.weight;
            
            int fromParent = findParent(from);
            int toParent = findParent(to);
            
            if (fromParent == toParent) continue;
            
            result += weight;
            
            parent[toParent] = fromParent;
        }
        
        
        System.out.println(result);
        
        br.close();
    }
    
    static int findParent (int node) {
        if (parent[node] == node) return node;
        return findParent(parent[node]);
    }
}