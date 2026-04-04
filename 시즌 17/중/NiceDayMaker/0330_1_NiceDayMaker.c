#include <stdio.h>

int main(){
    long long n, m, res = 1;
	scanf("%lld %lld", &n, &m);
    
    if(n >= m){
        res = 0;
    }
    else{
        for (long long i = n; i > 0; i--) {
			res *= i;
			res %= m;
			
			if (res == 0) { 
				break;
			}
		}
    }
    
    printf("%lld", res);
}