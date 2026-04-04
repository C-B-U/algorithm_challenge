int main(){
    int n;
    scanf("%d", &n);

    int x, max;
    scanf("%d", &max);

    for(int i = 1; i < n; i++){
        scanf("%d", &x);
        if(x > max){
            max = x;
        }
    }

    printf("%d", max);

    return 0;
}
