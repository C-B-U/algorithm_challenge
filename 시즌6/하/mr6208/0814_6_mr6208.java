import java.util.*;
import java.io.*;

public class Main {

 	public ArrayList<Integer> solution (int n, int[] arr) {
		ArrayList<Integer> answer = new ArrayList<>();
		Arrays.sort(arr);
		answer.add(arr[0]);
		answer.add(arr[arr.length-1]);

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
		for(int x : T.solution(n, arr)){
			System.out.print(x+" ");
		}
	}
}
