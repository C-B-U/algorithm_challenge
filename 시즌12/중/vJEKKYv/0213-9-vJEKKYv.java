package main;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성
        String str = input.nextLine(); // 문자열 입력 받기
        input.close(); // Scanner 객체 닫기
        
        int length = str.length(); // 문자열 길이
        
        for (int i = 0; i < length; i++) {
            if (isPalindrome(str.substring(i))) { // 부분 문자열이 팰린드롬인지 확인
                System.out.println(length + i); // 최소 길이 출력
                return;
            }
        }
    }
    
    private static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
