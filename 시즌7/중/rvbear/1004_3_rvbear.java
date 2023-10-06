import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stk.nextToken());
        int m = Integer.parseInt(stk.nextToken());

        int count = 0;
        for(int i = 0; i < n; i++) {
            String line = br.readLine();
            boolean flag = false;
            for(int j = 0; j < m; j++) {
                char c = line.charAt(j);
                if(c == '.') {
                    count = flag ? count += 2 : count;
                } else {
                    count++;
                    flag = flag ? false : true;
                }
            }
        }

        System.out.println(count/2);
        br.close();
    }
}