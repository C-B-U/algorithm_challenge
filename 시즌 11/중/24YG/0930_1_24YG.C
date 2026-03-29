#include <pthread.h>
#include <stdio.h>

int main() {
    int cSmester,cMajor,cCredit ; // 현재 학기, 전공, 학점 변수선언

    scanf("%d %d %d",&cSmester,&cMajor,&cCredit);  // 입력값을 변수에 저장
    int Major[10] = {0};                                // 전공과목 개설 수를 저장할 배열 생성
    int Refinement[10] = {0};                           // 교양과목 개설 수를 저장할 배열 생성

    for (int i=0; i<10; i++) {
        scanf("%d %d",&Major[i],&Refinement[i]);
    }

    cSmester = 8 - cSmester ;
    cMajor = 66 - cMajor ;
    cCredit = 130 - cCredit ;

    if (cMajor < 0 && cCredit < 0) {
        printf("Nice");
    }
    else {
        int pMajor =0 , pRefinement=0 ;
        for (int j=0; j<cSmester; j++) {
            pMajor += Major[j] ;
            if (Refinement[j] > 6-Major[j]) {
                pRefinement += 6-Major[j];
            }
            else {
                pRefinement += Refinement[j];
            }
        }
        if ((cCredit-((pMajor*3)+(pRefinement*3)) < 0) && (cMajor - (pMajor*3) <0 )) {
            printf("Nice");
        }
        else {
            printf("Nae ga wae");
        }
    }
}
