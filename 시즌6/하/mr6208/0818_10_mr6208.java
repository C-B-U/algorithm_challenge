import java.util.*;
import java.io.*;

public class Main {

	public float solution(int n, int[] arr){
		float answer = 0;
		Arrays.sort(arr);
		float max = arr[n-1];
		float sum = 0;
		for(int i = 0; i < n; i++){
			sum += arr[i]/max*100;
		}
		answer = sum/n;
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
		System.out.println(T.solution(n ,arr));		
		kb.close();
	}
}
