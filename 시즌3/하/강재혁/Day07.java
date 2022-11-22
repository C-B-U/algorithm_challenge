package 강재혁;

import java.util.*;

public class Day07 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] milk = new int[N];
        int count = 0;
        int next = 0;

        for (int i = 0; i < N; i++) {
            milk[i] = sc.nextInt();
        }

        for (int i:milk) {
            if (i == next && next == 0) {
                count++;
                next = 1;
                continue;
            }
            if (i == next && next == 1) {
                count++;
                next = 2;
                continue;
            }
            if (i == next && next == 2) {
                count++;
                next = 0;
                continue;
            }
        }
        System.out.println(count);
    }
}
