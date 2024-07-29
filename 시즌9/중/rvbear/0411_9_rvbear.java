import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int answer = 0;

        if(n <= 3) {
            answer = (n <= 2) ? 0 : 1;
        } else {
            answer = 2;
            int temp = 2;

            for(int i = 5; i <= n; i++) {
                answer += temp;
                if(i % 2 == 0) {
                    temp++;
                }
            }
        }

        System.out.println(answer);
    }
}