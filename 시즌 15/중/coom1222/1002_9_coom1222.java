package AlgorithmChallenge15;

import java.util.Scanner;

public class Day9 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] maxDp = new int[3];
        int[] minDp = new int[3];

        // 1. 첫 번째 줄을 DP 배열로 초기화.
        for (int i = 0; i < 3; i++) {
            int val = scanner.nextInt();
            maxDp[i] = val;
            minDp[i] = val;
        }

        // 2. 두 번째 줄부터 마지막 줄까지 반복하며 DP 배열을 갱신
        for (int j = 1; j < N; j++) {
            int n0 = scanner.nextInt();
            int n1 = scanner.nextInt();
            int n2 = scanner.nextInt();

            // DP 배열 값을 갱신할 때 윗 줄의 값이 필요하므로, 임시 변수로 저장
            int prevMax0 = maxDp[0];
            int prevMax1 = maxDp[1];
            int prevMax2 = maxDp[2];

            int prevMin0 = minDp[0];
            int prevMin1 = minDp[1];
            int prevMin2 = minDp[2];

            // 최대 점수 DP 배열 갱신
            maxDp[0] = n0 + Math.max(prevMax0, prevMax1);   // 1 + max(4,5)
            maxDp[1] = n1 + Math.max(prevMax0, Math.max(prevMax1, prevMax2));   // 2 + max(4, max(5,6))
            maxDp[2] = n2 + Math.max(prevMax1, prevMax2);   // 3 + max(5,6)

            // 최소 점수 DP 배열 갱신
            minDp[0] = n0 + Math.min(prevMin0, prevMin1);   // 1 + min(4,5)
            minDp[1] = n1 + Math.min(prevMin0, Math.min(prevMin1, prevMin2));
            minDp[2] = n2 + Math.min(prevMin1, prevMin2);
        }

        // 3. 최종 최대/최소 결과.
        int maxResult = Math.max(maxDp[0], Math.max(maxDp[1], maxDp[2]));
        int minResult = Math.min(minDp[0], Math.min(minDp[1], minDp[2]));

        // 4. 결과를 출력합니다.
        System.out.println(maxResult + " " + minResult);

        scanner.close();
    }
}
