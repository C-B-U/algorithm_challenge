#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 2000 //N, T �ִ밡 2000 |

int main() {
    int N, T, P;
    int solve[MAX][MAX]; // �����ں� ���� Ǯ�� ����
    int problem_score[MAX] = { 0 }; // �� ������ ����
    int score[MAX] = { 0 }; // �� �������� ���� ����
    int solved_count[MAX] = { 0 }; // �� �����ڰ� Ǭ ���� ��

    scanf("%d %d %d", &N, &T, &P);
    P--; 

    // �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            scanf("%d", &solve[i][j]); // i�� �����ڰ� j���� �����(1) �ƴϳ�(0)
        }
    }

    // �� ������ ���� = �� ������ �� Ǭ ��� ��
    for (int j = 0; j < T; j++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (solve[i][j] == 0)
                count++;
        }
        problem_score[j] = count; // j�� ���� ����
    }

    // �� �������� ������ Ǭ ���� �� ���
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            if (solve[i][j] == 1) {
                score[i] += problem_score[j]; // i�� �������� �� ����
                solved_count[i]++; // i�� �������� ���� ���� ��
            }
        }
    }

    // �ʸ��� ������ Ǭ ���� ��
    int philip_score = score[P];
    int philip_solved = solved_count[P];

    // ��� 
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
