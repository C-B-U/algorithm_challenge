package AlgorithmChallenge14;

import java.util.Scanner;

public class Day5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt(); // 테스트 케이스의 개수
        for (int i = 0; i < T; i++) {
            int number = scanner.nextInt(); // 네 자리 수 입력
            int steps = 0;

            // Kaprekar 상수 6174에 도달할 때까지 반복
            while (number != 6174) {
                String numStr = String.format("%04d", number);
                // 연산에서는 항상 4자리 수로 계산해야 하므로, 입력된 숫자가 4자리보다 작을 때 앞에 0을 붙여서 4자리로 만드는 것.
                char[] digits = numStr.toCharArray();

                // 재배열은 내림차순으로 정렬하여 가장 큰 수 생성
                java.util.Arrays.sort(digits);  // 오름차순 정렬
                String minNumStr = new String(digits);  // 오름차순 정렬된 문자열, 가장 작은 수
                String maxNumStr = new StringBuilder(minNumStr).reverse().toString();   // 내림차순 정렬된 문자열, 가장 큰 수

                // 문자열을 정수로 변환
                int minNum = Integer.parseInt(minNumStr);
                int maxNum = Integer.parseInt(maxNumStr);

                // Kaprekar 연산 수행
                number = maxNum - minNum;
                steps++;
            }
            System.out.println(steps); // 결과 출력
        }
        scanner.close();
    }
}
