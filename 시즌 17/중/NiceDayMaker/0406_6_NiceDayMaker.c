#include <stdio.h>

int main()
{
    long long pointer = 1, adder = 0, multiplier = 1;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int command;
        long long x;
        
        scanf("%d", &command);
        if (command != 3)
        {
            scanf("%lld", &x);
        }

        if (command == 0)
        {
            adder += x;
        }
        else if (command == 1)
        {
            multiplier *= x;
            adder *= x;
        }
        else if(command == 2)
        {
            pointer += x;
        }
        else{
            printf("%lld\n", pointer * multiplier + adder);
        }
    }

    return 0;
}