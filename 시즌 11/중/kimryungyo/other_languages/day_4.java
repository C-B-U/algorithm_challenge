import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();

        long result;

        if (B < 4) {
            result = 0;
        } else {
            if (A < 4) {
                A = 4;
            }
            if (A % 2 == 1) {
                A += 1;
            }
            if (B % 2 == 1) {
                B -= 1;
            }
            result = ((B / 2) - (A / 2) + 1) * ((A / 2) + (B / 2));
        }

        System.out.println(result);
    }
}