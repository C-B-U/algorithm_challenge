#include <stdio.h>
#include <string.h>

char tc[21] = "toycartoon";

int fmaxfinder(int i, int j, int tempc, char s[21]){
    if(tc[i] != s[j]) return tempc;
    else{
        if(i+1<strlen(tc) && j+1<strlen(s)){
            int t = fmaxfinder(i+1, j+1, tempc+1, s);
            return t;
        }
        else return (tempc+1);
    }
}

int lmaxfinder(int i, int j, int tempc, char s[21]){
    while(j<strlen(tc) && i<strlen(s)){
        if(tc[j] == s[i]){
            tempc++;
            i++; j++;
        }
        else return tempc;
    }
    return tempc;
}

int main() {
    char s[21];
    char res[42];
    scanf("%s", s);
    
    int i, fmaxc = 0, ftempc = 0, fmaxwhere = 0;
    for(i=0;i<strlen(tc);i++){
        ftempc = fmaxfinder(i, 0, 0, s);
        if(ftempc > fmaxc){
            fmaxwhere = i;
            fmaxc = ftempc;
        }
    }
    
    int ltempc = 0;
    for(i=fmaxc;i<strlen(s);i++){
        ltempc = lmaxfinder(i, fmaxwhere+fmaxc, 0, s);
        if(ltempc == strlen(s)-i){
            break;
        }
        else ltempc = 0;
    }
    
    int rear = 0;
    if(fmaxc == 0){
        for(i=0;i<strlen(tc);i++){
            res[rear++] = tc[i];
        }
        res[rear++] = '_';
        for(i=0;i<strlen(s);i++){
            res[rear++] = s[i];
        }
    }
    else{
        for(i=0;i<fmaxwhere;i++){
            res[rear++] = tc[i];
        }
        for(i=0;i<strlen(s);i++){
            res[rear++] = s[i];
        }
        for(i=fmaxwhere+ltempc+fmaxc;i<strlen(tc);i++){
            res[rear++] = tc[i];
        } 
    }
    res[rear] = '\0';
    
    if(strlen(res) > 20){
        printf("%s", tc);
    }
    else{
        printf("%s", res);
    }
    
    return 0;
}