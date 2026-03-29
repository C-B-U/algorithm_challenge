
import java.io.IOException;
import java.util.Scanner;

import static java.lang.Math.min;

public class Main {
    public static int find(int start_row, int start_col, char[][] chess) {
        int count = 0; // 첫번째 색을 기준으로 할 때

        char color = chess[start_row][start_col];
        for (int i = start_row; i < start_row + 8; i++) {
            for (int j = start_col; j < start_col + 8; j++) {
                if (chess[i][j] != color) {
                    count ++;
                }
                if (color == 'W')
                    color = 'B';
                else
                    color = 'W';
            }
//            이전 줄과 다음 줄의 색깔이 달라야 하므로
            if (color == 'W')
                color = 'B';
            else
                color = 'W';
        }
        int reverse_count = 64 - count; // 첫번째 색과 반대 색상을 기준으로 할 때

        return min(count, reverse_count); // 첫번째 색깔이 B일때와 W일때의 값 중 최솟값을 return
    }
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        scanner.nextLine();

        char[][] chess =   new char[N][M]; // NxM 크기의 체스판

//        체스판 생성
        for (int i = 0; i < N; i++) {
            String rowInput = scanner.next();
            for (int j = 0; j < M; j++) {
                chess[i][j] = rowInput.charAt(j);
            }
        }
        int min = 10000000;
        for (int a = 0; a < N-7; a++) {
            for (int b = 0; b < M-7; b++) {
                int find = find(a, b, chess);
                min = min(min, find);
            }
        }
        System.out.println(min);



    }
}
