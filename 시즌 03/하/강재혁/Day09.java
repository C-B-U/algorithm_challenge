package 강재혁;

import java.util.Scanner;

public class Day09 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        double max = -1;
        double total = 0;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            if (max < A[i]) {
                max = A[i];
            }
        }
        for (int i = 0; i < N; i++) {
            total += (A[i] / max) * 100;
        }
        System.out.println(total/N);
    }
}
