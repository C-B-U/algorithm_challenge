import java.io.*;
import java.util.*;

public class Day_01 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int parity = -1;
        boolean possible = true;

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            long r = Long.parseLong(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            int p = (int) ((r + c) % 2);

            if (parity == -1) {
                parity = p;
            } else if (parity != p) {
                possible = false;
            }
        }
        System.out.println(possible ? "YES" : "NO");
    }
}
