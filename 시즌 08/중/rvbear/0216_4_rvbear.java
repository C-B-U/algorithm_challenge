import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] input = new int[N];

        for(int i = 0; i < N; i++) {
            String[] temp = br.readLine().split(" ");
            input[i] = Integer.parseInt(temp[0]) - Integer.parseInt(temp[1]);
        }

        Arrays.sort(input);

        System.out.println((N%2 == 1) ? 1 : Math.abs(input[N/2] - input[N/2-1]) + 1);
    }
}