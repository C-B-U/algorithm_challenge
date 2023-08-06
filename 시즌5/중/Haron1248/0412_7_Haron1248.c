#include <stdio.h>
#include <stdlib.h>

typedef struct table {
	long long int num;
	int count;
} Army;

int main() {
	int n, size, i, j, index, state;
	char str[12];
	long long int num;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &size);
		Army* army = (Army*)calloc(size, sizeof(Army));
		state = 0;
		for (j = 0; j < size; j++) {
			scanf("%s", str);
			num = atoll(str);
			index = (num % size + size) % size;
			while (army[index].count != 0 && army[index].num != num) index = (index + 1) % size;
			if (army[index].count == 0)	army[index] = (Army){num, 1};
			else army[index].count++;
			if (army[index].count > size / 2) {
				state = 1;
				printf("%lld\n", army[index].num);
				while (getchar() != '\n');
				break;
			}
		}
		if (state == 0)	printf("SYJKGW\n");
		free(army);
	}
	return 0;
}
