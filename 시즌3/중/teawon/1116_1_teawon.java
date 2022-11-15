package teawon;

import java.util.*;
import java.io.*;
/*
 * 문제 주소 :  https://www.acmicpc.net/problem/1003
 * 15796KB | 172ms
 **/

public class Main {

    static int[][] paper_arr = new int[128][128];
    static int[] colorCount = new int[2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuffer sb = new StringBuffer();

        int N = Integer.parseInt(br.readLine()); // N개의 수

        paper_arr = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper_arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        check(0, 0, N);

        System.out.println(colorCount[0]);
        System.out.println(colorCount[1]);

    }

    public static void check(int y, int x, int size) { // 값이 다르다면 종이를 쪼개서 탐색 반복
        int value = paper_arr[y][x];
        for (int y_ = 0; y_ < size; y_++) {
            for (int x_ = 0; x_ < size; x_++) {
                if (paper_arr[y + y_][x + x_] != value) {
                    check(y, x, size / 2);
                    check(y + size / 2, x, size / 2);
                    check(y, x + size / 2, size / 2);
                    check(y + size / 2, x + size / 2, size / 2);
                    return;
                }
            }
        }
        colorCount[value]++;
    }
}
