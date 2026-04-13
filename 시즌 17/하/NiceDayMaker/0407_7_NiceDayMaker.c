#include <stdio.h>
#include <string.h>

int main()
{
    char S[1001] = {0}, T[1001] = {0};
    scanf("%s", S);
    scanf("%s", T);
    int len = strlen(T);
    char temp;

    while (len-- > 0)
    {
        if(T[len] == 'A')
        {
            T[len] = 0;
        }
        else if (T[len] == 'B')
        {
            T[len] = 0;
            for (int i = 0; i < len / 2; i++)
            {
                temp = T[i];
                T[i] = T[len - 1 - i];
                T[len - 1 - i] = temp;
            }
        }
        if (strcmp(S, T) == 0)
        {
            printf("1");
            return 0;
        }
    }

    printf("0");
    return 0;
}