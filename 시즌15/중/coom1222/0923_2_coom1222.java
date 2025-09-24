import java.util.*;
import java.io.*;

public class Main {

	static int N;
	static int[][] schedule;
	static int result;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine()); // N까지만 일 함
		schedule = new int[N][2];
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			schedule[i][0] = Integer.parseInt(st.nextToken()); // 상담 하는데 걸리는 일 수
			schedule[i][1] = Integer.parseInt(st.nextToken()); // 돈
		}
		
		result = 0;
		// 0일 부터 시작함
		dfs(0, 0);
		
		System.out.println(result);
	}
	
	static void dfs(int idx, int pay) {
		if(idx >= N) {
			result = Math.max(pay, result);
			return;
		}
		
		if(idx + schedule[idx][0] <= N) { // 상담을 끝마칠 수 있다면 -> 상담이 끝난 날짜와 상담비 넣음
			dfs(idx + schedule[idx][0], pay + schedule[idx][1]);
		} else { // 상담을 끝마칠 수 없다면 -> 상담이 끝난 날짜만 넘겨준다(탈출 조건으로 써먹음)
			dfs(idx + schedule[idx][0], pay);
		}
		
		// 이어서 상담하지 않고 날짜를 띄워서 새로운 날짜를 입력 (0일부터 마지막 날짜까지 다 훑을 수 있음)
		dfs(idx + 1, pay);
	}
	
}
