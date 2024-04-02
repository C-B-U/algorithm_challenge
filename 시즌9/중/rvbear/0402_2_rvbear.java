import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            int n = Integer.parseInt(br.readLine());

            if(n == 0) {
                break;
            }

            int[] charging = new int[n];
            for(int i = 0; i < n; i++) {
                charging[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(charging);

            boolean flag = true;
            for(int i = 1; i < n; i++) {
                if(charging[i] - charging[i-1] > 200) {
                    flag = false;
                    break;
                }
            }

            if(1422 - charging[charging.length - 1] > 100) {
                flag = false;
            }

            System.out.println(flag ? "POSSIBLE" : "IMPOSSIBLE");
        }
    }
}
