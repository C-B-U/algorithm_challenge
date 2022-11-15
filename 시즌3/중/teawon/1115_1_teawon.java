package teawon;

import java.util.*;
import java.io.*;
/*
 * 문제 주소 :  https://www.acmicpc.net/problem/1003
 * 15952KB | 156ms
 **/

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();

        int[] p_arr = new int[42]; // N의 범위는 최대 40이므로 41까지 파보나치 계산
        p_arr[0] = 1;
        p_arr[1] = 0;
        for (int i = 2; i < 42; i++) {
            p_arr[i] = p_arr[i - 1] + p_arr[i - 2];
        }
        int T = Integer.parseInt(br.readLine()); // Test케이스 개수
        for (int i = 0; i < T; i++) {
            int num = Integer.parseInt(br.readLine());
            sb.append(p_arr[num] + " " + p_arr[num + 1] + "\n");

        }
        System.out.print(sb);

    }

}
