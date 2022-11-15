package 강재혁;

import java.util.*;

public class Day02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean check[] = new boolean[2001];
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            int temp = sc.nextInt();
            check[temp + 1000] = true;
        }
        for (int i = 0; i < 2001; i++) {
            if (check[i]) {
                System.out.print(i-1000+" ");
            }
        }
    }
}

/*public class Day02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Set<Integer> num = new TreeSet<>();
        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            int temp = sc.nextInt();
            num.add(temp);
        }

        for (Integer i : num) {
            System.out.print(i+" ");
        }
    }
}*/
