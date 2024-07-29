import java.io.*;
import java.util.*;

public class Main {
    public static char[][] chess;
    public static int find(int x, int y) {           // 해당 위치부터 8번째 칸까지 체스판의 범위를 통해 값을 찾아줌 
        int B_count = 0;            // 체스판을 B부터 시작
        int W_count = 0;            // 체스판을 W부터 시작

        for (int i = x; i < x + 8; i++)
            for (int j = y; j < y + 8; j++) {
                if((i + j) % 2 == 0) {
                    if(chess[i][j] == 'B') W_count++;
                    else B_count++;
                }
                else {
                    if(chess[i][j] == 'W') W_count++;
                    else B_count++;
                }
            }

        return Math.min(B_count,W_count);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));       // 버퍼 스트림을 통해 입력
        StringTokenizer stk = new StringTokenizer(br.readLine());

        int col = Integer.parseInt(stk.nextToken());
        int row = Integer.parseInt(stk.nextToken());
        chess = new char[col][row];

        for (int i = 0; i < col; i++) {             // chess 배열에 값을 넣어줌
            String line = br.readLine();
            for (int j = 0; j < row; j++)
                chess[i][j] = line.charAt(j);
        }

        int ans = 1000000;

        for (int i = 0; i < col - 7; i++)
            for (int j = 0; j < row - 7; j++)           
                ans = Math.min(ans, find(i, j));        // 값을 넣어준 뒤 적은 값을 저장

        System.out.println(ans);                        // 가장 적은 값을 출력
        br.close();         // 입력 버퍼 스트림 닫아줌
    }
}