import java.util.Scanner;

public class Day_02 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNext()) {
            String s = scanner.next();

            int[] count = new int[26];

            for (int i = 0; i < s.length(); i++) {
                count[s.charAt(i) - 'A']++;
            }

            int oddCount = 0;
            char oddChar = 0;

            for (int i = 0; i < 26; i++) {
                if (count[i] % 2 != 0) {
                    oddCount++;
                    oddChar = (char) (i + 'A');
                }
            }

            if (oddCount > 1) {
                System.out.println("I'm Sorry Hansoo");
            } else {
                StringBuilder firstHalf = new StringBuilder();

                for (int i = 0; i < 26; i++) {
                    for (int j = 0; j < count[i] / 2; j++) {
                        firstHalf.append((char) (i + 'A'));
                    }
                }

                StringBuilder result = new StringBuilder(firstHalf);

                if (oddCount == 1) {
                    result.append(oddChar);
                }

                result.append(new StringBuilder(firstHalf).reverse());

                System.out.println(result.toString());
            }
        }
        scanner.close();
    }
}
