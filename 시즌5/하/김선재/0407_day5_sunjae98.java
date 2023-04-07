import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), ",");

        int[] A = new int[N];
        int[] B = new int[N - 1];


        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N - 1; i++) {
            B[i] = A[i + 1] - A[i];
        }

        for (int m = 2; m < K + 1; m++) {
            for (int l = 0; l < N - m; l++) {
                B[l] = B[l + 1] - B[l];
            }
        }

        if (K == 0) {
            for (int i = 0; i < N; i++) {
                if (i == N - 1) {
                    System.out.print(A[i]);
                } else {
                    System.out.print(A[i] + ",");
                }
            }
        } else {
            for (int i = 0; i < N - K; i++) {
                if (i == N - K - 1) {
                    System.out.print(B[i]);
                } else {
                    System.out.print(B[i] + ",");
                }
            }
        }

        br.close();
    }
}