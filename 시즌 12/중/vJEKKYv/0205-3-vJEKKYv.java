package main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // 입력 받기
        int n = input.nextInt();
        int d = 0;

        // n이 0보다 클 때까지 반복
        while (n > 0) {
            d = 0;
            
            // 콘을 지나는 횟수 (1, 2, 3, 4로 루프)
            for (int i = 1; i <= 4; i++) {
                // 출발 구간
                for (int j = 0; j < i; j++) {
                    n -= 5;
                    if (n <= 0) {
                        d += 5 + n;
                        break;
                    }
                    d += 5;
                }
                if (n <= 0) {
                    break;
                }

                // 복귀 구간
                for (int j = 0; j < i; j++) {
                    n -= 5;
                    if (n <= 0) {
                        d -= 5 + n;
                        break;
                    }
                    d -= 5;
                }
                if (n <= 0) {
                    break;
                }
            }
        }

        // 결과 출력
        System.out.println(d % 5 == 0 ? d / 5 : d / 5 + 1);

        // Scanner 객체 닫기
        input.close();
    }
}
