import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String encrypted = scanner.nextLine();

        int N = Integer.parseInt(scanner.nextLine());
        String[] words = new String[N];

        for (int i = 0; i < N; i++) {
            words[i] = scanner.nextLine();
        }

        for (int key = 0; key < 26; key++) {
            StringBuilder decrypted = new StringBuilder();
            for (char c : encrypted.toCharArray()) {
                decrypted.append((char) (97 + ((c - 97 + key) % 26)));
            }

            for (String word : words) {
                if (decrypted.toString().contains(word)) {
                    System.out.println(decrypted);
                    System.exit(0);
                }
            }
        }
    }
}