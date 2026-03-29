import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[] parent;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] tmp = br.readLine().split(" ");
		int n = Integer.parseInt(tmp[0]);
		int m = Integer.parseInt(tmp[1]);

        parent=new int[n+1];
		for(int i = 1; i <= n; i++) parent[i] = i;
        
        for(int i = 0; i < m; i++){
            String ab_arr[] = br.readLine().split(" ");
            int op = Integer.parseInt(ab_arr[0]);
            int a = Integer.parseInt(ab_arr[1]);
			int b = Integer.parseInt(ab_arr[2]);
            
            a = find(a);
            b = find(b); 
            
            if(op == 0 && a != b) union(a, b);
            else if(op == 1 && a != b) System.out.println("NO");
            else if(op == 1 && a == b) System.out.println("YES");
        }
    }
    
    public static void union(int a, int b) {
        parent[a] = b;
    }
    
    public static int find(int a) {
        if(parent[a] == a) return a;
        else return parent[a] = find(parent[a]);
    }
}
