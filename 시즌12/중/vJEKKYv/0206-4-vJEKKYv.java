package main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성
        int n = input.nextInt(); // 사용자로부터 정수 n 입력 받기
        input.close(); // Scanner 닫기
        
        long[] t = new long[n + 1]; // 동적 계획법을 위한 배열 선언
        t[0] = 1; // 초기값 설정
        
        // 점화식에 따라 배열 값 계산
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                t[i] += t[j] * t[i - 1 - j]; // t[i] = Σ (t[j] * t[i-1-j])
            }
        }
        
        System.out.println(t[n]); // 결과 출력
    }
}