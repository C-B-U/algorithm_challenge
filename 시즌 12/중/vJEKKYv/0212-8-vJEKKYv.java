package main;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성
        int N = input.nextInt(); // 정수 N 입력 받기
        input.close(); // Scanner 객체 닫기
        
        int[] dp = new int[N + 1]; // DP 테이블 생성
        Arrays.fill(dp, Integer.MAX_VALUE); // 초기값을 최댓값으로 설정
        dp[1] = 0; // 1은 연산이 필요 없음
        
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + 1; // 1을 빼는 연산
            if (i % 2 == 0) {
                dp[i] = Math.min(dp[i], dp[i / 2] + 1); // 2로 나누는 연산
            }
            if (i % 3 == 0) {
                dp[i] = Math.min(dp[i], dp[i / 3] + 1); // 3으로 나누는 연산
            }
        }
        
        System.out.println(dp[N]); // 최소 연산 횟수 출력
    }
}
