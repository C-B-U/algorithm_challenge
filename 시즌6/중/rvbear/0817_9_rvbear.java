import java.io.*;
import java.util.*;

public class Main {
    public static long gcd(long a, long b) {            // 유클리도 호제법
        return b == 0 ? a : gcd(b, a%b);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        long x = Long.parseLong(stk.nextToken());       // 가로 길이
        long y = Long.parseLong(stk.nextToken());       // 세로 길이

        System.out.println(x+y-gcd(x,y));               // 가로 + 세로 - 가로와 세로의 최대공약수
        br.close();
    }
}