import java.io.*;
import java.util.*;

public class Main {
    public static int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
        long a = x1 * y2 + x2 * y3 + x3 * y1;
        long b = y1 * x2 + y2 * x3 + y3 * x1;

        return a-b > 0 ? 1 : (a-b == 0 ? 0 : -1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] point = new int[3][2];
        for(int i = 0; i < 3; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            point[i][0] = Integer.parseInt(stk.nextToken());
            point[i][1] = Integer.parseInt(stk.nextToken());
        }

        System.out.println(ccw(point[0][0], point[0][1], point[1][0], point[1][1], point[2][0], point[2][1]));
        br.close();
    }
}