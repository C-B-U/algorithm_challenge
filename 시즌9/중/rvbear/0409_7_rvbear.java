import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());

            for(int j = 2; j <= N; j++) {
                int count = 0;
                while(N % j == 0) {
                    N /= j;
                    count++;
                }
                if(count != 0) {
                    stb.append(j).append(" ").append(count).append("\n");
                }
                if(N == 0) {
                    break;
                }
            }
        }

        System.out.print(stb);
    }
}