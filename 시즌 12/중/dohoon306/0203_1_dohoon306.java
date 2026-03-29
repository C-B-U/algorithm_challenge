
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R, C, Q;
        R = scanner.nextInt(); // 행
        C = scanner.nextInt(); // 열
        Q = scanner.nextInt(); // 쿼리 개수

        // 원본 배열 입력
        int[][] arr = new int[R + 1][C + 1]; // 1-based indexing을 위해 +1
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                arr[i][j] = scanner.nextInt();
            }
        }

        // 합 배열 생성
        int[][] sumArray = new int[R + 1][C + 1];
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                // 누적 합 계산: 현재 값 + 왼쪽 누적 합 + 위쪽 누적 합 - 왼쪽 위 대각선 누적 합
                sumArray[i][j] = arr[i][j] + sumArray[i - 1][j] + sumArray[i][j - 1] - sumArray[i - 1][j - 1];
            }
        }

        for (int i = 0; i < Q; i++) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int AO = scanner.nextInt();
            int BO = scanner.nextInt();

            // 영역 내 픽셀 수 계산
            int num = (AO - A + 1) * (BO - B + 1);

            // 영역 내 밝기 합 계산
            int sum = sumArray[AO][BO] - sumArray[A - 1][BO] - sumArray[AO][B - 1] + sumArray[A - 1][B - 1];

            // 평균 밝기 계산
            int result = sum / num;
            System.out.println(result);
        }
    }
}
