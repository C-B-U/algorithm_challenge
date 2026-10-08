#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char name[1000][60];
const char *key(const char* s)
{
	for (int i = 0; s[i]; i++)
	{
		if (isupper((unsigned char)s[i]))
		{
			return s + i;
		}
	}
	return s;
}
int comp(const void* a, const void* b)
{
	return strcmp(key((const char*)a), key((const char*)b));
}
int main()
{
	int n;
	char name[1000][51];
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		do
		{
			if (fgets(name[i], sizeof(name[i]), stdin) == NULL)
			{
				n = i;
				break;
			}
			name[i][strcspn(name[i], "\r\n")] = '\0';
		} while (name[i][0] == '\0');
	}
	qsort(name, n, sizeof(name[0]), comp);
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", name[i]);
	}
	return 0;
}
