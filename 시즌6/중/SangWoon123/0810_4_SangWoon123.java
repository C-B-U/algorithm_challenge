import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.parseInt(br.readLine());

        String[] words = new String[num];
        for (int i = 0; i < num; i++) {
            words[i]= br.readLine();
        }

        Set<Character> keys=new HashSet<>();

        for (String a : words) {
            String[] twoWords = a.split(" ");
            boolean firstOption = false;

            for (String character : twoWords) {
                char first = character.charAt(0);
                if (!keys.contains(first)) {
                    keys.add(Character.toLowerCase(first));
                    keys.add(Character.toUpperCase(first));

                    StringBuilder sb = new StringBuilder(character);
                    sb.insert(0, '[');
                    sb.insert(2, ']');

                    String newWord = a.replaceFirst(character, sb.toString());
                    System.out.println(newWord);
                    firstOption = true;
                    break;
                }
            }

            if (!firstOption) {
                boolean secondOption = false;

                for (int i = 0; i < twoWords.length; i++) {
                    for (int j = 0; j < twoWords[i].length(); j++) {
                        char temp = twoWords[i].charAt(j);
                        if (!keys.contains(temp)) {
                            keys.add(Character.toLowerCase(temp));
                            keys.add(Character.toUpperCase(temp));

                            StringBuilder sb = new StringBuilder(twoWords[i]);
                            sb.insert(j, '[');
                            sb.insert(j + 2, ']');

                            String newWord = a.replaceFirst(twoWords[i], sb.toString());
                            System.out.println(newWord);

                            secondOption = true;
                            break;
                        }
                    }
                    if (secondOption) {
                        break;
                    }
                }

                // 3번째 조건
                if (!secondOption) {
                    System.out.println(a);
                }
            }
        }
    }
}
