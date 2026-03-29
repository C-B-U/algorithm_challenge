import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] alphabet = new int[27];
    static int count, length;
    public static void dfs(char pre, int depth) {
        if(depth == length) {
            count++;
            return;
        }

        for(int i = 0; i < 27; i++) {
            if(alphabet[i] == 0) continue;

            if(pre != (char)(i+'a')) {
                alphabet[i]--;
                dfs((char)(i+'a'), depth + 1);
                alphabet[i]++;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        length = S.length();

        for(int i = 0; i < S.length(); i++) {
            alphabet[S.charAt(i) - 'a']++;
        }

        dfs(' ', 0);
        System.out.println(count);
    }
}