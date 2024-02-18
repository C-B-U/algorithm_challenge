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
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	      int N = Integer.parseInt(input.readLine());
	      int[] resultList = new int[N];
	      StringTokenizer st;
	      for (int i = 0; i < N; i++) {
	         st = new StringTokenizer(input.readLine());
	         resultList[i] = Integer.parseInt(st.nextToken()) - Integer.parseInt(st.nextToken());
	      }
	      Arrays.sort(resultList);
	 
	      if(N%2==1) System.out.println(1);
	      else System.out.println(Math.abs(resultList[N/2]-resultList[N/2-1])+1);
	}
}