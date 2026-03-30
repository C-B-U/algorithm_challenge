import java.util.*;
import java.io.*;

public class Main {

	public int solution(int n, int[] arr){
		int answer = 0;
		for(int i = 0; i < n; i++){
			int tmp = arr[i];
			int cnt = 0;
			if(arr[i]==1) continue;
			for(int j = 2; j <= Math.sqrt(tmp); j++){
				if(tmp % j == 0){
					cnt++;
					break;
				}
			}
			if(cnt == 0) answer++;
		}

		return answer;
	}
    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		int n = kb.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++){
			arr[i] = kb.nextInt();
		}
		System.out.println(T.solution(n, arr));		
		kb.close();
	}
}
