import java.util.*;
import java.io.*;

public class Main {

	public long solution(int a, int b, int c){
		if(b>=c) return -1;
		long answer = 0;
		long revenue = c-b;
		answer = a / revenue;
		answer++;
		return answer;
	}
    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		int a = kb.nextInt();
		int b = kb.nextInt();
		int c = kb.nextInt();
		System.out.println(T.solution(a, b, c));		
		kb.close();
	}
}
