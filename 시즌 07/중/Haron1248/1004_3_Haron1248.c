#include <stdio.h>
#include <stdlib.h>

int main() {
	int h, w, isOpen = -1;
	double area = 0;
	scanf("%d %d", &h, &w);
	int* openUpside = (int*)calloc(w, sizeof(int));

	char temp;
	for (int i = 0; i < h; i++) {
		getchar();
		for (int j = 0; j < w; j++) {
			scanf("%c", &temp);
			if (temp == '/' || temp == '\\') {
				area += .5;
				isOpen *= -1;
				if (openUpside[j] == 1) openUpside[j] = 0;
				else openUpside[j] = 1;
			}
			else if (temp == '.') {
				if (isOpen == 1) {
					area += 1;
					openUpside[j] = 1;
				}
				else if (openUpside[j] == 1) {
					area += 1;
					isOpen = 1;
				}
			}
		}
	}

	printf("%g\n", area);
}
