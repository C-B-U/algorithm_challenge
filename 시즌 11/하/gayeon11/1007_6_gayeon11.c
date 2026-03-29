#include <stdio.h>

int main() {
    int N;  // N = 후보자 수
    scanf("%d", &N);

    int dasom, maxVotes = 0, voteCount = 0;
    int votes[100];  // 각 후보자의 표 수를 저장하는 배열

    scanf("%d", &dasom); // 다솜이 표 수

    for (int i = 1; i < N; i++) {
        scanf("%d", &votes[i]); // 다른 후보자 표 수
    }

    if (N == 1) { // 다솜이가 혼자 후보일 경우.
        printf("0\n");
        return 0;
    }

    while (1) {// 다솜이가 가장 많은 표를 얻을 때까지 반복하기
        // 다솜이 이외의 후보자 중 가장 많은 표를 가진 후보 찾기
        int maxIndex = 1;
        for (int i = 2; i < N; i++) {
            if (votes[i] > votes[maxIndex]) {
                maxIndex = i;
            }
        }

        if (dasom > votes[maxIndex]) { // 다솜이가 이미 가장 많은 표를 가졌을 경우
            break;
        }

        // 다솜이의 표 1 증가, 가장 많은 표 후보의 표 1 감소 [매수]
        dasom++;
        votes[maxIndex]--;
        voteCount++;  // [매수] 표 수 기록
    }

    printf("%d\n", voteCount);

    return 0;
}