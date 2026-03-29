import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] temp = br.readLine().split(" ");

        int N = Integer.parseInt(temp[0]);
        int K = Integer.parseInt(temp[1]);

        temp = br.readLine().split(" ");
        long[] exp = new long[N];

        for(int i = 0; i < N; i++) {
            exp[i] = Integer.parseInt(temp[i]);
        }

        Arrays.sort(exp);

        long max = 0;
        int stone = 1;
        for(int i = 1; i < N; i++) {
            if(stone < K) {
                max += exp[i] * stone++;
            } else {
                max += exp[i] * K;
            }
        }

        System.out.println(max);
    }
}