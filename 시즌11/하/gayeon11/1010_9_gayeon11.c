#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // ���� �޸�
    int* score = (int*)malloc(N * sizeof(int)); // ������ ��� + malloc �Լ�

    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]); // ���� ���� �Է�
    }

    int max_score = -1, max_id = 100001;
    for (int i = 0; i < M; i++) {
        int id, total_score = 0;
        scanf("%d", &id);

        for (int j = 0; j < N; j++) {
            char result;
            scanf(" %c", &result);
            if (result == 'O') {
                total_score += score[j];
            }
        }

        // �ִ� ���� �� ���� ��ȣ ����
        if (total_score > max_score || (total_score == max_score && id < max_id)) {
            max_score = total_score;
            max_id = id;
        }
    }

    printf("%d %d\n", max_id, max_score);

    // ���� �޸� ����
    free(score);

    return 0;
}
