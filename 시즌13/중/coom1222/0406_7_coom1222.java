import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        double res = 0.0;
        double p = Combination(n, m);

        while(m >= k){
            if(n - m < m - k){
                k++;
                continue;
            }

            double c = Combination(m, k) * Combination(n-m, m-k);

            res += c/p;
            k++;
        }

        System.out.println(res);
    }

    static long Combination(int n, int r){
        int p = 1;
        int c = 1;

        while(r > 0){
            c *= n--;
            p *= r--;
        }
        return c / p;
    }
}
