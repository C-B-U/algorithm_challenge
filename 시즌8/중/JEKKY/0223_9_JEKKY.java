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
	static int n, delete;
    static int[] parent;
    static int count;
    static boolean[] visited;
	public Problem() {}
	public void solve() throws IOException {
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        parent = new int[n];
        int root = 0;
        for(int i = 0; i < n; i++) {
            parent[i] = input.nextInt();        
            if(parent[i] == -1) root = i;
        }
        delete = input.nextInt();
        
        deleteNode(delete);
            
        count = 0;
        visited = new boolean[n];
        countLeaf(root);
            
        System.out.println(count);
        input.close();
    }
    
    public static void deleteNode(int d) {
        parent[d] = -2;
        for(int i = 0; i < n; i++) {
            if(parent[i] == d) {
                deleteNode(i);
            }
        }
    }
    
    public static void countLeaf(int s) {
        boolean isLeaf = true;
        visited[s] = true;
        if(parent[s] != -2) {
            for(int i = 0; i < n; i++) {
                if(parent[i] == s && visited[i] == false) {
                    countLeaf(i);
                    isLeaf = false;
                }
            }
            if(isLeaf) count++;
        }
    }
}