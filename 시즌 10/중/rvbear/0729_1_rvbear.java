import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] a, b;
    public static void change(int i, int j) {           // 3*3 행렬 값 바꾸기
        for(int x = i; x < i+3; x++) {
            for(int y = j; y <j+3; y++) {
                a[x][y] = a[x][y] == 0 ? 1 : 0;
            }
        }
    }
    public static void make_h(String line, int i) {     // 행렬에 값 저장
        for(int j = 0; j < m; j++) {
            if(i < n) {
                a[i][j] = line.charAt(j) - '0';
            } else {
                b[i-n][j] = line.charAt(j) - '0';
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(stk.nextToken());          // 행
        m = Integer.parseInt(stk.nextToken());          // 열
        a = new int[n][m]; b = new int[n][m];           // 행렬 a, 행렬 b

        for(int i = 0; i < n*2; i++) {
            String line = br.readLine();
            make_h(line, i);
        }

        int count = 0;                                  // 바꾼 횟수

        for(int i = 0; i < n; i++) {                    // 행렬 바꾸기
            for(int j = 0; j < m; j++) {
                if(a[i][j] != b[i][j] && i+2 < n && j+2 < m) {
                    change(i, j);
                    count++;
                }
            }
        }

        for(int i = 0; i < n; i++) {                    // 바뀐 행렬이 같은지 확인
            for(int j = 0; j < m; j++) {
                if(a[i][j] != b[i][j]) {                // 다른 부분이 있다면 count에 -1 저장
                    count = -1;
                }
            }
        }

        System.out.println(count);                      // 결과값 출력
        br.close();
    }
}