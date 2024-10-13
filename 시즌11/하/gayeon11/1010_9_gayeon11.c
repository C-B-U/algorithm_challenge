#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 동적 메모리
    int* score = (int*)malloc(N * sizeof(int)); // 포인터 사용 + malloc 함수

    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]); // 문제 배점 입력
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

        // 최대 점수 및 수험 번호 갱신
        if (total_score > max_score || (total_score == max_score && id < max_id)) {
            max_score = total_score;
            max_id = id;
        }
    }

    printf("%d %d\n", max_id, max_score);

    // 동적 메모리 해제
    free(score);

    return 0;
}
