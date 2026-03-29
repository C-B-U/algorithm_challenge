import java.util.*;
import java.io.*;

public class Main {

	public int solution (String str) {
		int answer = 0;
		for(String x : str.split(" ")){
			if(x!="") answer++;
		}
		return answer;
}


    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		String str = kb.nextLine();

		System.out.println(T.solution(str));

	}
}
