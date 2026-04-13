package algorChal17;

import java.util.Scanner;

public class Day4 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long M = sc.nextLong();

        // 안전한 시간
        long dimiTime = 0;

        for (int i = 0; i < N; i++) {
            long A = sc.nextLong();
            // 각 친구를 볼 수 있는 최대 시간은 A - 1
            dimiTime += (A - 1);
        }

        // 각 친구를 볼 수 있는 최대 시간을 모두 더한게 M 보다 크면 DIMI, 크면 OUT
        if (dimiTime >= M) {
            System.out.println("DIMI");
        } else {
            System.out.println("OUT");
        }

    }
}
