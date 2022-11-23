package 강재혁;

import java.util.Scanner;

public class Day08 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {

            int a = sc.nextInt();
            int b = sc.nextInt();
            int gcd = getGcd(a, b);
            int lcm = (a * b) / gcd;
            System.out.println(lcm + " " + gcd);
        }
    }

    private static int getGcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getGcd(b, a % b);
    }
}
