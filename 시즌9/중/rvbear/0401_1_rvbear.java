import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] A = br.readLine().split(" ");
        int A1 = Integer.parseInt(A[0]);
        int An = Integer.parseInt(A[N-1]);

        for(int i = 0; i < N-2; i++) {
            if(i == N-3) {
                A1--;
                An--;
            } else if(A1 < An) {
                An--;
            } else {
                A1--;
            }
        }

        System.out.println(Math.max(A1, An));
    }
}