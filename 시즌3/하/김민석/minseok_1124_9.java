import java.util.Scanner;
import java.util.Arrays;

public class minseok_1124_9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, i;
        N = scanner.nextInt();
        if (N < 0 || N > 1000) System.exit(0);
        double ary[] = new double[N];
        double nextAry[]=new double[N];
        for (i = 0; i < N; i++) {
            ary[i] = scanner.nextDouble();
        }
        Arrays.sort(ary);
        final double topnum=ary[N-1];

        double sum=0;
        for (i = 0; i < N; i++) {
            sum=sum+ary[i]/topnum*100;
        }

        double aver=sum/N;

        System.out.print(aver);
        scanner.close();
    }
}
