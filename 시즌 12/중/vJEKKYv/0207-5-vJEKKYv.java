package main;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성
        int X = input.nextInt(); // 찾고자 하는 X번째 분수
        input.close(); // Scanner 객체 닫기
        
        int diagonal = 1; // 대각선 번호
        int sum = 0; // 현재까지 대각선의 총 개수
        
        // X가 포함된 대각선 찾기
        while (sum + diagonal < X) {
            sum += diagonal;
            diagonal++;
        }
        
        int indexInDiagonal = X - sum; // 해당 대각선에서의 위치
        
        int numerator, denominator;
        
        if (diagonal % 2 == 0) { // 짝수 대각선일 때
            numerator = indexInDiagonal;
            denominator = diagonal - indexInDiagonal + 1;
        } else { // 홀수 대각선일 때
            numerator = diagonal - indexInDiagonal + 1;
            denominator = indexInDiagonal;
        }
        
        System.out.println(numerator + "/" + denominator); // 결과 출력
    }
}
