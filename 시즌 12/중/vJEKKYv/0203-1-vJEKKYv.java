package main;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Scanner 객체를 사용하여 입력을 처리
        Scanner input = new Scanner(System.in);
        StringBuilder sb = new StringBuilder(); // 출력 최적화를 위한 StringBuilder 사용

        // 변수 선언
        int width, height, question, sum;
        int r1, c1, r2, c2;
        
        // 누적 합을 저장할 배열 (1-based index 사용)
        int[][] picture;

        // 첫 줄 입력: 너비(width), 높이(height), 질의 개수(question)
        width = input.nextInt();
        height = input.nextInt();
        question = input.nextInt();

        // 배열 초기화 (1-based index이므로 크기를 +1)
        picture = new int[width + 1][height + 1];

        // 2차원 배열 입력 및 누적 합 계산
        for (int x = 1; x <= width; x++) {
            sum = 0; // 현재 행의 누적 합

            for (int y = 1; y <= height; y++) {
                sum += input.nextInt(); // 입력값을 누적 합에 추가
                picture[x][y] = sum + picture[x - 1][y]; // 이전 행 값과 더하여 누적 합 저장
            }
        }

        // 질의 처리 (평균 값 계산)
        for (int x = 0; x < question; x++) {
            // 입력: 질의 영역의 좌표 (r1, c1) ~ (r2, c2)
            r1 = input.nextInt();
            c1 = input.nextInt();
            r2 = input.nextInt();
            c2 = input.nextInt();

            // 부분 합을 이용하여 해당 영역의 평균 계산 후 저장
            int totalSum = picture[r2][c2] - picture[r1 - 1][c2] - picture[r2][c1 - 1] + picture[r1 - 1][c1 - 1];
            int area = (r2 - r1 + 1) * (c2 - c1 + 1); // 영역 크기
            sb.append(totalSum / area).append("\n"); // 평균 값 추가
        }

        // 최종 결과 출력
        System.out.print(sb);
        input.close(); // Scanner 객체 닫기 (자원 해제)
    }
}
