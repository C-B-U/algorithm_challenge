#include <stdio.h>
#include <string.h>

int main() {
    char arr[5][11];  
    int Exist = 0;    

    for (int i = 0; i < 5; i++) {
        scanf("%s", arr[i]);  
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j]=='F'&& arr[i][j+1] == 'B'&& arr[i][j+2] == 'I') {
                printf("%d ", i + 1);
                Exist = 1;
                break;
            }
        }
    }

    if (Exist ==0) {
        printf("HE GOT AWAY!");
    }

}
