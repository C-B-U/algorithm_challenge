import java.util.Arrays;
import java.util.Scanner;

public class kimhalin_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int[] list = new int[num];
        for (int i=0; i<num; i++) {
            list[i] = scanner.nextInt();
        }
        Arrays.sort(list);
        for (int i=0; i<num; i++)
            System.out.println(list[i]);
    }
}
