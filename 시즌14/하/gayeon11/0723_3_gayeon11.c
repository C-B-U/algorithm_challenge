#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 2000 //N, T 최대가 2000 |

int main() {
    int N, T, P;
    int solve[MAX][MAX]; // 참가자별 문제 풀이 여부
    int problem_score[MAX] = { 0 }; // 각 문제의 점수
    int score[MAX] = { 0 }; // 각 참가자의 최종 점수
    int solved_count[MAX] = { 0 }; // 각 참가자가 푼 문제 수

    scanf("%d %d %d", &N, &T, &P);
    P--; 

    // 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            scanf("%d", &solve[i][j]); // i번 참가자가 j번을 맞췄냐(1) 아니냐(0)
        }
    }

    // 각 문제의 점수 = 그 문제를 못 푼 사람 수
    for (int j = 0; j < T; j++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (solve[i][j] == 0)
                count++;
        }
        problem_score[j] = count; // j번 문제 점수
    }

    // 각 참가자의 점수와 푼 문제 수 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            if (solve[i][j] == 1) {
                score[i] += problem_score[j]; // i번 참가자의 총 점수
                solved_count[i]++; // i번 참가자의 맞춘 문제 수
            }
        }
    }

    // 필립의 점수와 푼 문제 수
    int philip_score = score[P];
    int philip_solved = solved_count[P];

    // 등수 
    int rank = 1;

    for (int i = 0; i < N; i++) {
        if (i == P) continue;

        if (score[i] > philip_score) {
            rank++;
        }
        else if (score[i] == philip_score) {
            if (solved_count[i] > philip_solved) {
                rank++;
            }
            else if (solved_count[i] == philip_solved && i < P) {
                rank++;
            }
        }
    }

    printf("%d %d\n", philip_score, rank);

    return 0;
}
