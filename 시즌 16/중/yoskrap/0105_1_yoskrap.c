#include <stdio.h>

int main(){
    long long int w, h, f, c, x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &w, &h, &f, &c, &x1, &y1, &x2, &y2);
    long long int ff;
    if (f<=w/2) ff = f;
    else if (f==w) ff = 0;
    else ff = w-f;
    
    long long int res = 0;
    if (x2<=ff){
        res = (x2-x1)*(y2-y1)*(c+1)*2;
    }
    else if (x1>=ff){
        res = (x2-x1)*(y2-y1)*(c+1);
    }
    else{
        res += (ff-x1)*(y2-y1)*(c+1)*2;
        res += (x2-ff)*(y2-y1)*(c+1);
    }
    
    printf("%lld", w*h-res);
    
    return 0;
}