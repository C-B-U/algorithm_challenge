#include<stdio.h>
#include<stdlib.h>
#define SCORE 3
#define MIN_MAIN_SCORE 66
#define MIN_SCORE 130
#define MAX_GRADE 8

int main() {
    int grade, mainScore, Score;
    int maxClass;
    int class[10][2];
    // mainScore은 전공학점 Score은 비전공학점
    scanf("%d %d %d", &grade, &mainScore, &Score);

    for (int i = 0; i < 10; i++) {
        scanf("%d %d", &class[i][0], &class[i][1]);
    }

    for (int i = 0; i < MAX_GRADE-grade; i++) {
        maxClass = 6;
        //전공과목
        if (maxClass >= class[i][0]) {
            mainScore += class[i][0] * SCORE;
            Score += class[i][0] * SCORE;
            maxClass -= class[i][0]; 
        }
        else {
            mainScore += maxClass * SCORE; 
            Score += maxClass * SCORE;
            maxClass = 0;
        }
        //비전공과목
        if (maxClass >= class[i][1]) { 
            Score += class[i][1] * SCORE;
        }
        else {
            Score += maxClass * SCORE;
        }
    }
    if (mainScore >= MIN_MAIN_SCORE && Score >= MIN_SCORE) {
        printf("Nice\n");
    }
    else {
        printf("Nae ga wae\n");
    }
    return 0;
}
