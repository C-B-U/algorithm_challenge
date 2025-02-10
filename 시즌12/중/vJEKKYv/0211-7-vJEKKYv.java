package main;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성
        int N = input.nextInt(); // 현재 랭킹 리스트에 있는 점수 개수
        int newScore = input.nextInt(); // 새로운 점수
        int P = input.nextInt(); // 랭킹 리스트의 최대 크기
        
        List<Integer> scores = new ArrayList<>(); // 랭킹 리스트
        for (int i = 0; i < N; i++) {
            scores.add(input.nextInt());
        }
        input.close(); // Scanner 객체 닫기
        
        // 새로운 점수를 랭킹 리스트에 삽입하여 정렬
        scores.add(newScore);
        scores.sort(Collections.reverseOrder());
        
        // 새로운 점수의 순위 찾기
        int rank = 1;
        for (int i = 0; i < scores.size(); i++) {
            if (scores.get(i) == newScore) {
                rank = i + 1;
                break;
            }
        }
        
        // 랭킹 리스트 크기를 초과하는 경우 예외 처리
        if (N == P && scores.get(scores.size() - 1) == newScore) {
            System.out.println(-1);
        } else {
            System.out.println(rank);
        }
    }
}
