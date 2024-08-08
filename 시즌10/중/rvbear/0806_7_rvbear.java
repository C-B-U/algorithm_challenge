import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk;
        int num;

        int N = Integer.parseInt(br.readLine());
        stk = new StringTokenizer(br.readLine());
        Map<Integer, Integer> a = new HashMap<>();

        for(int i = 0; i < N; i++) {
            num = Integer.parseInt(stk.nextToken());
            a.put(num, a.getOrDefault(num, 0) + 1);
        }

        stk = new StringTokenizer(br.readLine());
        int count = 0;

        for(int i = 0; i < N; i++) {
            num = Integer.parseInt(stk.nextToken());
            int result = a.getOrDefault(num, 0);

            if(result == 0) {
                count++;
            } else if(result == 1) {
                a.remove(num);
            } else {
                a.put(num, result - 1);
            }
        }

        System.out.println(count);
    }
}