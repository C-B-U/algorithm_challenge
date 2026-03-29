package AlgorithmChallenge14;

import java.util.Scanner;

public class Day8 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int 고정비용 = scanner.nextInt(); // 고정 비용
        int 가변비용 = scanner.nextInt(); // 가변 비용
        int 판매가 = scanner.nextInt(); // 노트북 가격

        int 손익분기점 = -1; // 손익분기점 초기화, -1은 손익분기점이 없음을 의미
        scanner.close();

        while (true) {
            // 손익분기점 계산: 고정비용 + (가변비용 * 판매 대수) < 판매가 * 판매 대수
            // 즉, 고정비용 < (판매가 - 가변비용) * 판매 대수
            if (판매가 <= 가변비용) {
                System.out.println(손익분기점); // 판매가가 가변비용 이하인 경우 손익분기점이 존재하지 않음
                // 판매가가 가변비용 이하인 경우 손익분기점이 존재하지 않음
                break;
            }

            손익분기점++;
            if (고정비용 < ((판매가 - 가변비용) * 손익분기점)) {
                // 손익분기점이 발견되면 루프 종료
                System.out.println(손익분기점);
                break;
            }
        }
    }
}
