import java.io.*;
import java.util.*;

public class Main {
    public static int check(int x1, int y1, int r1, int x2, int y2, int r2) {
        double distance = Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2);

        if(x1 == x2 && y1 == y2 && r1 == r2) {          // 중점이 같으면서 반지름도 같은 경우
            return -1;
        } else if(distance > Math.pow(r1+r2, 2)) {      // 두 원의 반지름 합보다 중점간 거리가 더 길 때
            return 0;
        } else if(distance < Math.pow(r2-r1, 2)) {      // 원 안에 원이 있으나 내접하지 않을 때
            return 0;
        } else if(distance == Math.pow(r2-r1, 2)) {     // 내접할 때
            return 1;
        } else if(distance == Math.pow(r2+r1, 2)) {     // 외접할 때
            return 1;
        } else {
            return 2;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());            // test case 개수
        StringBuilder stb = new StringBuilder();

        for(int i = 0; i < t; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(stk.nextToken());     // 조규현 x 좌표
            int y1 = Integer.parseInt(stk.nextToken());     // 조규현 y 좌표
            int r1 = Integer.parseInt(stk.nextToken());     // 조규현과 류재명의 거리
            int x2 = Integer.parseInt(stk.nextToken());     // 백승환 x 좌표
            int y2 = Integer.parseInt(stk.nextToken());     // 백승환 y 좌표
            int r2 = Integer.parseInt(stk.nextToken());     // 백승환과 류재명의 거리

            stb.append(check(x1, y1, r1, x2, y2, r2)).append("\n");
        }

        System.out.print(stb);
        br.close();
    }
}