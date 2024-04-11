import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static String reverse(String s) {
        switch(s) {
            case "1":
                return "3";
            case "2":
                return "4";
            case "3":
                return "1";
            default:
                return "2";
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringBuilder forward = new StringBuilder();
        StringBuilder reverse = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            String t = st.nextToken();
            forward.append(t);
            reverse.insert(0, reverse(t));
        }

        Set<String> set = new HashSet<>();

        for (int i = 0; i < N; i++) {
            set.add(forward.toString());
            set.add(reverse.toString());

            forward.append(forward.charAt(0));
            reverse.append(reverse.charAt(0));

            forward.deleteCharAt(0);
            reverse.deleteCharAt(0);
        }

        int count = 0;
        StringBuilder answer = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            StringBuilder stb = new StringBuilder();

            for (int j = 0; j < N; j++) {
                stb.append(st.nextToken());
            }

            if (set.contains(stb.toString())) {
                count++;
                for (int j = 0; j < N; j++) {
                    answer.append(stb.charAt(j)).append(" ");
                }
                answer.append("\n");
            }
        }

        System.out.println(count);
        System.out.print(answer);
    }
}