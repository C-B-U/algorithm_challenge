import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

//        System.out.println("배열의 수를 입력하세요");
        int n = sc.nextInt();
        int[] array = new int[n];

//        System.out.println("n개의 정수를 입력하세요");
        for (int i = 0; i < n; i++ ) {
            array[i] = sc.nextInt();
        }

        Arrays.sort(array);

        System.out.println(array[n-1]);
    }
}
