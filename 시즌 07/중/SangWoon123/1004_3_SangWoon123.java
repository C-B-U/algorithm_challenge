
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    // 1. / or \ 일경우 0.5 넓이, /와\안의 .은 1의 넓이를 가진다.
    // 2. \ or / 이후 2개이전에 나오는 .은 넓이 1 그외에는 무시
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        String[][] map = new String[h][w];

        for (int i = 0; i < h; i++) {
            String str = br.readLine();
            for (int j = 0; j < w; j++) {
                map[i][j] = String.valueOf(str.charAt(j));
            }
        }

        int slapCount = 0;
        int answer = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j].equals("\\") || map[i][j].equals("/")) slapCount++;
                if (slapCount == 2) {
                    answer += 1;
                    slapCount = 0;
                }

                if (slapCount == 1) {
                    if (map[i][j].equals(".")) {
                        answer += 1;
                    }
                }

            }
        }
        System.out.println(answer);
    }
}
