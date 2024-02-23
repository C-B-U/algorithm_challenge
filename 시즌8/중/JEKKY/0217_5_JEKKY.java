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
	public Problem() {}
	public void solve() throws IOException {
		int Red = 0;
		int Green = 1;
		int Blue = 2;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
 
		int N = Integer.parseInt(br.readLine());
 
		int[][] Cost = new int[N][3];
 
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
 
			Cost[i][Red] = Integer.parseInt(st.nextToken());
			Cost[i][Green] = Integer.parseInt(st.nextToken());
			Cost[i][Blue] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 1; i < N; i++) {
			Cost[i][Red] += Math.min(Cost[i - 1][Green], Cost[i - 1][Blue]);
			Cost[i][Green] += Math.min(Cost[i - 1][Red], Cost[i - 1][Blue]);
			Cost[i][Blue] += Math.min(Cost[i - 1][Red], Cost[i - 1][Green]);
		}
		
		System.out.println(Math.min(Math.min(Cost[N - 1][Red], Cost[N - 1][Green]), Cost[N - 1][Blue]));
	}
}