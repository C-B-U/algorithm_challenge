package Main;
import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		Problem P = new Problem();
		P.solve();
	}
}
class Problem {
	public Problem() {}
	public void solve() throws IOException {
		Scanner input = new Scanner(System.in);
        String A = input.next();
        String B = input.next();
		int result = A.length();
		for (int i = 0; i < (B.length() - A.length()+1); i++) {
			int tmp = 0;
			for (int j = 0; j < A.length(); j++) {
				if (A.charAt(j) != B.charAt(j+i)) {
					tmp++;
				}
			}
			if (result > tmp) {
				result = tmp;
			}
		}
		System.out.println(result);
		input.close();
	}
}