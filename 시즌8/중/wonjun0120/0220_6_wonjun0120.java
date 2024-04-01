import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[] alphabet = new int[27];
    static int cnt;
    static int sLen;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        sLen = s.length();

        for (int i = 0; i < s.length(); i++) {
            alphabet[s.charAt(i) - 'a']++; 
        }

        dfs(0, ' ');
        System.out.println(cnt);

    }

    public static void dfs(int idx, char c){
        if (idx == sLen){
            cnt++;
            return;
        }

        for (int i = 0; i < 27; i++){
            if (alphabet[i] == 0) continue;

            if (c != (char)(i + 'a')){
                alphabet[i]--;
                dfs(idx + 1, (char)(i + 'a'));
                alphabet[i]++;
            }

        }
    }
}




