
string[] input = Console.ReadLine()!.Split();
double W = double.Parse(input[0]);
double H = double.Parse(input[1]);
int N = int.Parse(input[2]);

double length = 0.0;
if (N % 2 == 0)
    length = H * ((N - 2) / 2);
else
    length = H * (Math.Pow((N - 1), 2) / (2 * N));

Console.WriteLine(length.ToString("F6"));