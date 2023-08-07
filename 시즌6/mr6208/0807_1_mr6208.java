import java.util.*;
import java.io.*;

public class Main {

	public int solution (int[] arr) {
		int answer = 0;
		int sum = 0;
		for(int i = 0; i < arr.length; i++){
			int tmp = arr[i] * arr[i];
			sum += tmp;
		}
		answer = sum%10;
		return answer;
}


    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		int arr[] = new int[5];
		for(int i = 0; i < 5; i++){
			arr[i] = kb.nextInt();
		}

		System.out.println(T.solution(arr));
		
	}
}
