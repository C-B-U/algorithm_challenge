import java.io.*;
import java.util.StringTokenizer;

public class Day_07 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[][] cost = new int[N][3];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken()); // R
            cost[i][1] = Integer.parseInt(st.nextToken()); // G
            cost[i][2] = Integer.parseInt(st.nextToken()); // B
        }

        int prevR = cost[0][0];
        int prevG = cost[0][1];
        int prevB = cost[0][2];

        for (int i = 1; i < N; i++) {
            int currentR = cost[i][0] + Math.min(prevG, prevB);
            int currentG = cost[i][1] + Math.min(prevR, prevB);
            int currentB = cost[i][2] + Math.min(prevR, prevG);

            prevR = currentR;
            prevG = currentG;
            prevB = currentB;
        }

        int result = Math.min(prevR, Math.min(prevG, prevB));
        System.out.println(result);
    }
}
