package Day1;

import java.util.Scanner;

public class Day3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 입력 받기
        int N = sc.nextInt(); // 참가자 수
        int T = sc.nextInt(); // 문제 수
        int P = sc.nextInt(); // 필립의 ID

        int[][] results = new int[N][T]; // 각 참가자의 문제별 결과

        // 각 참가자의 문제 해결 여부 입력
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < T; j++) {
                results[i][j] = sc.nextInt();
            }
        }

        // 각 문제별 점수 계산 (해당 문제를 풀지 못한 참가자 수)
        int[] problemScores = new int[T];
        for (int j = 0; j < T; j++) {
            int unsolvedCount = 0;
            for (int i = 0; i < N; i++) {
                if (results[i][j] == 0) {
                    unsolvedCount++;
                }
            }
            problemScores[j] = unsolvedCount;
        }

        // 각 참가자의 총 점수와 푼 문제 수 계산
        int[] totalScores = new int[N];
        int[] solvedCount = new int[N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < T; j++) {
                if (results[i][j] == 1) {
                    totalScores[i] += problemScores[j];
                    solvedCount[i]++;
                }
            }
        }

        // 필립의 점수와 푼 문제 수
        int philipScore = totalScores[P - 1];
        int philipSolved = solvedCount[P - 1];

        // 필립의 등수 계산
        int rank = 1;
        for (int i = 0; i < N; i++) {
            if (i == P - 1) continue; // 필립 자신은 제외

            // 더 높은 점수를 받은 참가자
            if (totalScores[i] > philipScore) {
                rank++;
            }
            // 같은 점수지만 더 많은 문제를 푼 참가자
            else if (totalScores[i] == philipScore && solvedCount[i] > philipSolved) {
                rank++;
            }
            // 같은 점수, 같은 문제 수지만 ID가 더 빠른 참가자
            else if (totalScores[i] == philipScore && solvedCount[i] == philipSolved && (i + 1) < P) {
                rank++;
            }
        }

        // 결과 출력
        System.out.println(philipScore + " " + rank);
    }

}
