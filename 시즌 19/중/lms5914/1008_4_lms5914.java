import java.io.*;
import java.util.Arrays;

public class Day_04 {

    public static String getKey(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (Character.isUpperCase(s.charAt(i))) {
                return s.substring(i);
            }
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim());
        String[] names = new String[n];

        for (int i = 0; i < n; i++) {
            names[i] = br.readLine();
        }

        Arrays.sort(names, (a, b) -> {
            String keyA = getKey(a);
            String keyB = getKey(b);
            return keyA.compareTo(keyB);
        });

        StringBuilder sb = new StringBuilder();
        for (String name : names) {
            sb.append(name).append("\n");
        }
        System.out.print(sb);
    }
}
