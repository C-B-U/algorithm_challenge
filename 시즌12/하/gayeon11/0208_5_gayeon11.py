n = int(input())

fibo = [0, 1, 1]

for i in range (3, n + 1):
    fibo.append(fibo[i - 2] + fibo[i - 1])
    i += 1

print(fibo[n]) 

"""
// c언어로 작성하려고 했으나 c언어로는 아직 너무 어려워서 실패. ㅠㅠ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i;
	int fibo[5000] = { 0 };
	fibo[0] = 0;
	fibo[1] = 1;

	scanf("%d", &n);

	for (i = 0; i < n-1; i++) {
		fibo[i + 2] = fibo[i] + fibo[i + 1];
	}
	
	printf("%d", fibo[n]);
	return 0;
} 

라고 코드를 작성했지만 -> int형으로는 값을 다 표현할 수 없다고 하여 -> long long형을 사용했고,.. 같은 이유로 또 실패.
1차원 배열 2개 혹은 2차원 배열을 사용하려고 시도했지만 아직 개념 공부가 덜 되어서 실패...
"""