#include <stdio.h>
#include <stdlib.h>

typedef struct coord {
    int i;
    int c;
} coord;

int n;
coord arr[200000];
int dists[200000];

int compare(const void *a , const void *b) 
{ 
    coord *pa = (coord*)a;
    coord *pb = (coord*)b;

    return pb->c - pa->c;
}

int main(){
    scanf("%*d %d", &n);    

    for(int i = 0; i < n; ++i){
        scanf("%*d %d", &arr[i].c);
        arr[i].i = i;
    }

    qsort(arr , n , sizeof(coord) , compare);

    for(int i = 0; i < n; ++i){
        dists[arr[i].i] = n - i;
    }

    printf("YES\n");
    for(int i = 0; i < n; ++i){
        printf("%d ", dists[i]);
    }
}
