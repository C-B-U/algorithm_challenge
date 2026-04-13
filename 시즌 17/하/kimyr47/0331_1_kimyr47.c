#include <stdio.h>
#include <string.h>
int main() {
    char S[101];
    scanf("%s", S);

    int hasA=0, hasB=0, hasC=0;

    for (int i=0; i<strlen(S); i++) {
        if (S[i]=='A') hasA=1;
        else if(S[i]=='B') hasB=1;
        else if(S[i]=='C') hasC=1;
    }

    for (int i=0; i<strlen(S); i++) {
        if (hasA) {
            S[i]='A';
        }
        else if (hasB) {
            if(S[i]=='C' || S[i]=='D' || S[i]=='F')
            S[i]='B';
        } 
        else if (hasC) {
            if(S[i]=='D' || S[i]=='F')
            S[i]='C';
        else S[i]='A';
        }
    }
    printf("%s\n", S);

    return 0;
}
