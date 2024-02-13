import java.util.Scanner;

public class Main {

    static int[] dp = new int[1001];
    static int[] arr;
    static int result;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        arr = new int[t + 1];
        for(int i = 0; t > i ; ++i) {
            arr[i] = sc.nextInt();
        }

        for(int i = 0 ; t > i ; ++i) {
            System.out.println(solve(arr[i]));
        }
    }

    public static int solve(int x) {

        if(x == 0) return 1;
        if(x == 1) return 1;
        if(x == 2) return 5;
        if(x == 3) return 11;
        if(dp[x] != 0) return dp[x];

        result = solve(x - 1) + 4 * solve(x - 2) ;

        for(int i = 3; x >= i; ++i) {
            if(i % 2 == 0) {
                result += 3 * solve(x - i);
            }
            if(i % 2 != 0) {
                result += 2 * solve(x - i);
            }
        }
        return dp[x] = result;
    }
}
