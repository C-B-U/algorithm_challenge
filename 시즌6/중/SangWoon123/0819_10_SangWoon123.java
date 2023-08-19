
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int compare = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0;
        int end = 0;
        int result = Integer.MAX_VALUE;
        int sum = 0;




        while (true) {
            if (sum >= compare) {
                if (result > end - start) {
                    result = end - start;
                }
                sum -= arr[start++];
            } else {
                if (end == N) {
                    break;
                }
                sum += arr[end++];
            }
        }

        if (result == Integer.MAX_VALUE) {
            System.out.println(0);
        } else {
            System.out.println(result );
        }


    }


}