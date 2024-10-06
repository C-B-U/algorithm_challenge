#include <stdio.h>
int main(void) {
	int N, A, B;
	int major, non_major;

	scanf("%d %d %d", &N, &A, &B);

	for (int i = 0; i < (8-N); i++) {
		scanf("%d %d", &major, &non_major);
		for (int j = 0; j < 6; j++) {
			if (major > 0) {
				A += 3;
				B += 3;
				major -= 1;
			} else if (non_major > 0) {
				B += 3;
				non_major -= 1;
			}
		}
	}

	if ((A >= 66) && (B >= 130)) {
		printf("Nice\n");
	} else {
		printf("Nae ga wae\n");
	}

}