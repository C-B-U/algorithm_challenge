#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int count_dash = 0;
    int area = 0;

    char input;

    scanf("%d %d", &x, &y);
    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            scanf("%c", &input);
            if (input == '\\' || input == '/')
                ++count_dash;
            else if (count_dash % 2 == 1)
                ++area;
        }
    }
    printf("%d", area + (count_dash / 2));
    return 0;
}