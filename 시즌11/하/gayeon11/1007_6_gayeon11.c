#include <stdio.h>

int main() {
    int N;  // N = �ĺ��� ��
    scanf("%d", &N);

    int dasom, maxVotes = 0, voteCount = 0;
    int votes[100];  // �� �ĺ����� ǥ ���� �����ϴ� �迭

    scanf("%d", &dasom); // �ټ��� ǥ ��

    for (int i = 1; i < N; i++) {
        scanf("%d", &votes[i]); // �ٸ� �ĺ��� ǥ ��
    }

    if (N == 1) { // �ټ��̰� ȥ�� �ĺ��� ���.
        printf("0\n");
        return 0;
    }

    while (1) {// �ټ��̰� ���� ���� ǥ�� ���� ������ �ݺ��ϱ�
        // �ټ��� �̿��� �ĺ��� �� ���� ���� ǥ�� ���� �ĺ� ã��
        int maxIndex = 1;
        for (int i = 2; i < N; i++) {
            if (votes[i] > votes[maxIndex]) {
                maxIndex = i;
            }
        }

        if (dasom > votes[maxIndex]) { // �ټ��̰� �̹� ���� ���� ǥ�� ������ ���
            break;
        }

        // �ټ����� ǥ 1 ����, ���� ���� ǥ �ĺ��� ǥ 1 ���� [�ż�]
        dasom++;
        votes[maxIndex]--;
        voteCount++;  // [�ż�] ǥ �� ���
    }

    printf("%d\n", voteCount);

    return 0;
}