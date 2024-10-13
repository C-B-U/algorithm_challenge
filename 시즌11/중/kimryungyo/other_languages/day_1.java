import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int majors = scanner.nextInt();
        int total = scanner.nextInt();
        int remain_semester = 8 - N;

        for (int i = 0; i < remain_semester; i++) {
            int major = scanner.nextInt();
            int non_major = scanner.nextInt();

            for (int j = 0; j < 6; j++) {
                if (major > 0) {
                    majors += 3;
                    total += 3;
                    major -= 1;
                } else if (non_major > 0) {
                    total += 3;
                    non_major -= 1;
                }
            }
        }

        if (total >= 130 && majors >= 66) {
            System.out.println("Nice");
        } else {
            System.out.println("Nae ga wae");
        }
    }
}