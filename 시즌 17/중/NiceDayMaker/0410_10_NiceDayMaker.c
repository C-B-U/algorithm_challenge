#include <stdio.h>

char arr[500001];
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", arr);

    int totalH = 0, totalO = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'H')
            totalH++;
        else
            totalO++;
    }

    if (totalH != 2 * totalO)
    {
        printf("mix");
        return 0;
    }

    for (int i = 0, h = 0; i < n; i++)
    {
        if (arr[i] == 'H')
            h++;
        else
        {
            h--;
            if (h < 0)
            {
                printf("mix");
                return 0;
            }
        }
    }
    for (int i = n - 1, h = 0; i >= 0; i--)
    {
        if (arr[i] == 'H')
            h++;
        else
        {
            h--;
            if (h < 0)
            {
                printf("mix");
                return 0;
            }
        }
    }
    printf("pure");
    return 0;
}
