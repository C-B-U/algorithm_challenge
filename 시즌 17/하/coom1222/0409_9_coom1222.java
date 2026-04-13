import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // N개의 애플파이
        int N = sc.nextInt();

        // 연속으로 배치된 K를 먹을거다
        int K = sc.nextInt();

        // 맛있는 정도를 나타내는 값인 A_n이 공백으로 구분되어 주어진다.
        int[] deliciousA = new int[N];
        for (int i = 0; i < N; i++) {
            deliciousA[i] = sc.nextInt();
        }

        // 배열 복사
        int[] deliciousB = Arrays.copyOf(deliciousA, 2*deliciousA.length);
        for (int i = N; i < deliciousB.length-1; i++) {
            deliciousB[i] = deliciousA[i-N];
        }

     

        int tempMax = 0;
        int Max = 0;
        // 0부터 연속된 K개의 최대합 구하기 -> 배열을 슬라이딩 윈도우 형식으로 탐색해보자!
        for (int i = 0; i < K; i++) {
            tempMax += deliciousA[i];
            Max = tempMax;
        }

        // 하나씩 옮겨가기
        for (int i = K; i < N + K - 1; i++) {
            tempMax = tempMax - deliciousB[i-K] + deliciousB[i];

            if(tempMax > Max){
                Max = tempMax;
            }
        }

        System.out.println(Max);
    }
}
