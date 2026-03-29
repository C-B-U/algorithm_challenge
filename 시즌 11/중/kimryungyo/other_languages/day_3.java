import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        int[] pots = new int[N];
        Arrays.fill(pots, K);

        int day = 0;
        int idx = 0;
        while (true) {
            day += 1;

            for (int i = idx; i < idx + A; i++) {
                pots[i] += B;
            }

            for (int i = 0; i < N; i++) {
                pots[i] -= 1;
                if (pots[i] == 0) {
                    System.out.println(day);
                    System.exit(0);
                }
            }

            idx += A;
            if (idx == N) {
                idx = 0;
            }
        }
        
    }
}