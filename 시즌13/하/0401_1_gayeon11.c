#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int get_digital_root(char* num) { // ������ ��Ʈ ���ϴ� �Լ� ����.
    int sum;

    while (strlen(num) > 1) { // �� �ڸ� ���ڰ� �� ������ �ݺ�.
        sum = 0;

        for (int i = 0; num[i] != '\0'; i++) {
            sum += num[i] - '0'; // ���� -> ���� ��ȯ ---> ���ϱ�.
        }
        sprintf(num, "%d", sum); 
        // �հ踦 �ٽ� ���ڿ��� ��ȯ�ϰ�,,, �ݺ�.
    }

    return num[0] - '0'; 
    // ���������� ���� �� �ڸ� ���ڸ� ��ȯ�ϱ�.
}


int main() {
    char num[1001]; 

    while (1) {
        scanf("%s", num);

        if (num[0] == '0' && num[1] == '\0') break; // �Է��� ���������

        printf("%d\n", get_digital_root(num));
    }

    return 0;
}
