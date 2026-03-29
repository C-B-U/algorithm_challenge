import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        boolean[] isPrime = new boolean[100001];
        for (int i = 2; i <= 100000; i++) isPrime[i] = true;

        for (int i = 2; i * i <= 100000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 100000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int[] primes = new int[9593]; // 100,000 이하의 소수 개수는 9592개
        int primeCount = 0;
        for (int i = 2; i <= 100000; i++) {
            if (isPrime[i]) {
                primes[primeCount++] = i;
            }
        }

        int Roop = scanner.nextInt();

        for (int r = 0; r < Roop; r++) {
            int K = scanner.nextInt();
            int min = Integer.MAX_VALUE;

            for (int i = 0; i < primeCount; i++) {
                for (int j = i + 1; j < primeCount; j++) {
                    if (primes[i] > 100000000 / primes[j]) break;

                    int product = primes[i] * primes[j];

                    if (product >= K) {
                        if (product < min) {
                            min = product;
                        }
                        break; 
                    }
                }
            }

            System.out.println(min);
        }
    }
}
