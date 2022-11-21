import java.util.*;
import java.io.*;

/*
 * 문제 주소 :  https://www.acmicpc.net/problem/1074
 **/
public class Main {

    static int count = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken()); // 행
        int c = Integer.parseInt(st.nextToken()); // 열

        int total = (int) (Math.pow(2, N));
        find(r, c, total);
        System.out.println(count);
    }

    public static void find(int r, int c, int gap) {
        gap /= 2;

        if (gap == 0) {
            return;
        } else {

            if (r < gap && c < gap) { // 1사분면
                find(r, c, gap);
            } else if (r < gap && c >= gap) { // 2사분면
                count += (gap * gap);
                find(r, c - gap, gap);
            } else if (r >= gap && c < gap) { // 3사분면
                count += (gap * gap * 2);
                find(r - gap, c, gap);
            } else {
                count += (gap * gap * 3);
                find(r - gap, c - gap, gap);
            }
        }
    }
}