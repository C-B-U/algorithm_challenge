package silver._4.Q1459;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));       // 버퍼 스트림을 통해 입력
        StringTokenizer stk = new StringTokenizer(br.readLine());
        long x = Long.parseLong(stk.nextToken());      // 집의 x 위치
        long y = Long.parseLong(stk.nextToken());      // 집의 y 위치
        long w = Long.parseLong(stk.nextToken());      // 평행이동시 걸리는 시간
        long s = Long.parseLong(stk.nextToken());      // 대각선으로 이동시 걸리는 시간

        long c1, c2, c3;

        // 평행이동만 하는 경우
        c1 = (x + y) * w;
        // 대각선으로만 이동하는 경우
        if((x + y) % 2 == 0) {                  // x+y가 짝수인 경우는 대각선으로만 이동이 가능
            c2 = Math.max(x, y) * s;
        } else {                                // x+y가 홀수인 경우는 대각선 + 평행이동 한 번이 필요
            c2 = (Math.max(x, y) - 1) * s + w;
        }
        // 대각선 + 평행이동으로 이동하는 경우
        c3 = (Math.min(x, y) * s) + Math.abs(x-y) * w;

        // 세가지 경우 중 가장 작은 경우의 수 출력
        System.out.println(Math.min(Math.min(c1, c2), c3));
        br.close();         // 입력 버퍼 스트림 닫아줌
    }
}