import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N;
    static int[] contents;
    public static int solve() {
        Arrays.sort(contents);

        for(int i = N - 1; i >=0; i--) {
            int num = contents[i];
            int count = 0;

            for(int j = 0; j < N; j++) {
                if(num == contents[j]) {
                    count++;
                }
            }

            if(num == count) {
                return num;
            }
        }

        for(int i = 0; i < N; i++) {
            if(contents[i] == 0) {
                return -1;
            }
        }

        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        contents = new int[N];

        for(int i = 0; i < N; i++) {
            contents[i] = Integer.parseInt(input[i]);
        }

        System.out.println(solve());
        br.close();
    }
}