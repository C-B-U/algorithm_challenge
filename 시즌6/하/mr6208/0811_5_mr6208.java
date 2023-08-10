import java.util.*;
import java.io.*;

public class Main {

	public void solution (int[] arr) {
		while(true){
			boolean check = false;
			for(int i = 0; i < arr.length-1; i++){
				if(arr[i]>arr[i+1]){
					int tmp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = tmp;
					for(int x : arr){
						System.out.print(x+" ");
					}
					System.out.println();
					check = true;
				}
			}
			if(!check) break;
		}
}


    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		int [] arr = new int[5];
		for(int i = 0; i < 5; i++){
			arr[i] = kb.nextInt();
		}
		T.solution(arr);
	}
}
