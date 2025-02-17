package main;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성
        int T = Integer.parseInt(input.nextLine()); // 테스트 케이스 개수 입력 받기
        
        for (int t = 1; t <= T; t++) {
            String line = input.nextLine().toLowerCase(); // 입력 문자열을 소문자로 변환
            int[] freq = new int[26]; // 알파벳 빈도를 저장할 배열
            
            // 문자열을 순회하며 알파벳 빈도 계산
            for (char c : line.toCharArray()) {
                if (c >= 'a' && c <= 'z') { // 알파벳인 경우만 처리
                    freq[c - 'a']++;
                }
            }
            
            int minCount = Integer.MAX_VALUE; // 최소 등장 횟수를 저장할 변수 초기화
            for (int count : freq) {
                minCount = Math.min(minCount, count); // 알파벳 중 최소 등장 횟수 찾기
            }
            
            // 팬그램 유형 판별
            String result;
            if (minCount == 0) {
                result = "Not a pangram"; // 최소 등장 횟수가 0이면 팬그램이 아님
            } else if (minCount == 1) {
                result = "Pangram!"; // 최소 등장 횟수가 1이면 일반 팬그램
            } else if (minCount == 2) {
                result = "Double pangram!!"; // 최소 등장 횟수가 2이면 더블 팬그램
            } else {
                result = "Triple pangram!!!"; // 최소 등장 횟수가 3 이상이면 트리플 팬그램
            }
            
            // 결과 출력
            System.out.println("Case " + t + ": " + result);
        }
        input.close(); // Scanner 객체 닫기
    }
}