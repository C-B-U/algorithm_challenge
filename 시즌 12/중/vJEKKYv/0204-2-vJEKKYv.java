package main;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        int[] queries = new int[T];
        int maxK = 0;

        for (int i = 0; i < T; i++) {
            queries[i] = input.nextInt();
            if (queries[i] > maxK) {
                maxK = queries[i];
            }
        }

        // 에라토스테네스의 체를 사용하여 100,000 이하의 소수 목록 생성
        int limit = 100000;
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }

        // 소수 쌍의 곱을 저장할 TreeSet (자동 정렬 및 중복 제거)
        TreeSet<Integer> primeProducts = new TreeSet<>();
        int primeCount = primes.size();

        for (int i = 0; i < primeCount; i++) {
            for (int j = i + 1; j < primeCount; j++) {
                long product = (long) primes.get(i) * primes.get(j);
                if (product > 200000) {
                    break;
                }
                primeProducts.add((int) product);
            }
        }

        // 각 쿼리에 대해 결과 출력
        for (int k : queries) {
            System.out.println(primeProducts.ceiling(k));
        }

        input.close();
    }
}
