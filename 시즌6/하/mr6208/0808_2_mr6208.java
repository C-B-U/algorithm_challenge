import java.util.*;
import java.io.*;

public class Main {

	public int solution (int x, int y, int w, int h) {
		int answer = 0;
		
		int xMin = Math.min(x, w-x);
		int yMin = Math.min(y, h-y);

		answer = Math.min(xMin, yMin);

		return answer;
}


    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		Main T = new Main();
		int x = kb.nextInt();
		int y = kb.nextInt();
		int w = kb.nextInt();
		int h = kb.nextInt();

		System.out.println(T.solution(x,y,w,h));
		
	}
}
