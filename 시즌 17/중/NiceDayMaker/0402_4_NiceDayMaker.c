#include <stdio.h>

int main(){
    int n, m, tmp;
    
    scanf("%d %d", &n, &m);

    char title[n][12];
    int power[n];

    for(int i = 0; i < n; i++){
        scanf("%s %d", title[i], &power[i]);
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &tmp);

        int left = 0, right = n - 1, mid = (left + right) / 2;
        while (left <= right) {
			mid = (left + right) / 2;

			if (tmp <= power[mid]) 
				right = mid - 1;
			else
				left = mid + 1;
		}

		if (tmp > power[mid]) { 
			printf("%s\n", title[mid + 1]);
		}
		else{
			printf("%s\n", title[mid]);
        }
    }
}