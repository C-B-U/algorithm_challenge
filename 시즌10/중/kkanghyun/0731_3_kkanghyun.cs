static int CountHansu(int N)
{
    int count = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (IsHansu(i))
            ++count;
    }

    return count;
}

static bool IsHansu(int number)
{
    if (number < 100) // 1 ~ 99
    {
        return true;
    }
    else
    {
        int[] digits = GetDigits(number);
        int diff = digits[0] - digits[1];
        for (int i = 1; i < digits.Length - 1; ++i)
        {
            if (digits[i] - digits[i + 1] != diff)
                return false;
        }

        return true;
    }
}

static int[] GetDigits(int number)
{
    string numberStr = number.ToString();
    int[] digits = new int[numberStr.Length];
    for (int i = 0; i < numberStr.Length; ++i)
    {
        digits[i] = numberStr[i] - '0';
    }

    return digits;
}

int N = int.Parse(Console.ReadLine()!);

Console.WriteLine(CountHansu(N));