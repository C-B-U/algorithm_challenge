import java.util.*;
import java.io.*;

public class Main {

	public ArrayList<Integer> solution (int n1, int n2) {
		ArrayList<Integer> answer = new ArrayList<>();
		answer.add(n1*(n2%10));
		answer.add(n1*((n2%100)/10));
		answer.add(n1*(n2/100));
		answer.add(n1*n2);
		return answer;
}


    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		int n1 = kb.nextInt();
		int n2 = kb.nextInt();

		for(int x : T.solution(n1, n2)){
			System.out.println(x);
		}		
	}
}
