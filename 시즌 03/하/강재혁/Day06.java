package 강재혁;

import java.util.List;
import java.util.Scanner;

public class Day06 {
    private static final String GOOD = " is acceptable.";
    private static final String BAD = " is not acceptable.";
    private static final List<String> VOWEL = List.of("a", "e", "i", "o", "u");
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            String word = sc.nextLine();
            if (word.equals("end")) {
                break;
            }

            if (isVowelContains(word)
                    && is3word(word)
                    && isSameLetterInRow(word)) {
                System.out.println("<" + word + ">" + GOOD);
            } else {
                System.out.println("<" + word + ">" + BAD);
            }
        }
    }

    private static boolean isVowelContains(String word) {
        boolean validation = false;
        for (String str : VOWEL) {
            if (word.contains(str)) {
                validation = true;
            }
        }
        return validation;
    }

    private static boolean is3word(String word) {
        int countMo = 0;
        int countJa = 0;
        for (int i = 0; i < word.length(); i++) {
            String str = Character.toString(word.charAt(i));
            if (VOWEL.contains(str)) {
                countJa = 0;
                countMo++;
            } else {
                countJa++;
                countMo = 0;
            }

            if (countMo == 3 || countJa == 3) {
                return false;
            }
        }
        return true;
    }

    private static boolean isSameLetterInRow(String word) {
        char[] c = word.toCharArray();
        if (word.length() == 1) {
            return true;
        }
        for (int i = 0; i < c.length-1; i++) {
            if (c[i] == c[i + 1]) {
                if (c[i] != 'e' && c[i] != 'o') {
                    return false;
                }
            }
        }
        return true;
    }
}
