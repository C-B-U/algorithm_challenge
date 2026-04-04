import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        if (n >= m) { // n팩토리얼 내에 m이 곱해져 있을 것이니까
            System.out.println(0); // 당연히 n!은 m으로 나누어 떨어질 것.
            return;
        }

        // n < m인 경우
        // (A * B) mod M = (A mod M * B mod M) mod M = N 이 공식을 쓰지 않으면 오버플로우가 일어나버린다.
        long res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % m;
            if (res == 0) break;
        }
        System.out.println(res % m);
    }
}