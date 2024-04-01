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
	int[] alphabet = new int[27];
    int count;
    int length;
	public Problem() {}
	public void solve() throws IOException {
	    Scanner input = new Scanner(System.in);
	    String str = input.next();
	    length = str.length();
	    for (int i = 0; i < str.length(); i++)alphabet[str.charAt(i)-'a']++;

	    dfs(0,' ');
	    System.out.println(count);
	    input.close();
	    }

	    void dfs(int index,char pre){
	        if (index==length){
	            count++;
	            return;
	        }

	        for (int i = 0; i < 27; i++){
	            if (alphabet[i]==0)continue;

	            if (pre != (char) (i+'a')){
	                alphabet[i]--;
	                dfs(index+1, (char)(i+'a'));
	                alphabet[i]++;
	            }

	        }
	    }
}