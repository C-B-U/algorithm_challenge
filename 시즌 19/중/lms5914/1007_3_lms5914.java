import java.util.Scanner;

public class Day_03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        StringBuilder sb = new StringBuilder();
        if ((num & 8) != 0) sb.append('U');
        if ((num & 4) != 0) sb.append('C');
        if ((num & 2) != 0) sb.append('G');
        if ((num & 1) != 0) sb.append('A');

        String uniqueChars = sb.toString();

        char baseChar = uniqueChars.charAt(0);
        while (uniqueChars.length() < 4) {
            uniqueChars += baseChar;
        }

        System.out.println(uniqueChars);
        sc.close();
    }
}
