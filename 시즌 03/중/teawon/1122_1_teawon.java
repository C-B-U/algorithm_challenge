
import java.util.*;
import java.io.*;

/*
 * 문제 주소 :  https://www.acmicpc.net/problem/1449
 * 14228KB | 136ms
 * 
*/

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 물이 새는 개수
        int L = Integer.parseInt(st.nextToken()); // 테이프의 길이

        boolean[] leak_place = new boolean[1002];

        int count = 0; // 테이프의 개수

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int index = Integer.parseInt(st.nextToken());
            leak_place[index] = true;
        }

        for (int i = 1; i < 1002; i++) {
            if (leak_place[i]) { // 물이 샌다면 해당 지점 막는다.
                count++;
                for (int l = 0; l < L; l++) {
                    if (i + l < 1002)
                        leak_place[i + l] = false;
                }
            }
        }

        System.out.println(count);
    }

}