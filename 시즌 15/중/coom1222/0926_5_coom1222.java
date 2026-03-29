package AlgorithmChallenge15;

import java.util.Scanner;

public class Day5 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();  // 나무의 수
        int M = scanner.nextInt();  // 집에 가져가야 하는 나무의 길이

        int[] heights = new int[N];
        // 적어도 M미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값
        int max = 0;

        for (int i = 0; i < N; i++) {
            heights[i] = scanner.nextInt();
            if (heights[i] > max) {
                max = heights[i];
            }
        }

        int min = 0;

        // 중간 값 구하기(초기 자르는 위치)
        while (min < max) {

            int mid = min + (max - min) / 2;
            long sum = 0;   // 단일 나무의 길이가 최대 1,000,000,000 (10억), long으로 선언

            for (int height : heights) {
                // 잘린 나무의 길이 합산
                if (height - mid > 0) {
                    sum += (height - mid);
                }
            }

            // 자른 나무의 길이 합이 M작다는 것은
            // 자르는 위치(높이)가 높다는 의미, max를 줄여야함
            if (sum < M) {
                max = mid;
            }
            // 자른 나무의 길이 합이 M보다 크거나 같다는 것은
            // 자르는 위치(높이)가 낮다는 의미, min을 늘려야함
            else {
                min = mid + 1;
            }
        }
        System.out.println(min -1);
        scanner.close();
    }
}
