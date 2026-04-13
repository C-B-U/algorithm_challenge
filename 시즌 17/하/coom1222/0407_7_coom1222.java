import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 이게 피보나치인걸 문제를 한참 보다가 알았다.
        int k =  sc.nextInt();

        int a = 1, b = 0;
        for (int i = 0; i < k; i++) {
            int temp = a;
            a = b;
            b = temp + b;
        }

        System.out.println(a + " " + b);

    }
}
