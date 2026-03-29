
import java.io.*;
import java.util.*;

public class Main {
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        // 체스판 작성
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        String[][] map = new String[n][m];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = String.valueOf(str.charAt(j));
            }
        }

        // row-8, col-8 각 8*8 체스판 경우의 수 for문으로 돌기
        for (int i = 0; i < n - 7; i++) {
            for (int j = 0; j < m - 7; j++) {
                // W가 먼저 오는 경우
                int wCount = check(i, j, true, map);
                // B가 먼저 오는 경우
                int bCount = check(i, j, false, map);

                min=Math.min(min,wCount);
                min=Math.min(min,bCount);
            }
        }

        System.out.println(min);
    }

    static int check(int x,int y,boolean table,String[][] map){
        int count=0;
        boolean check=table;
        for(int i=x;i<x+8;i++){
            for(int j=y;j<y+8;j++){
                if(check&&map[i][j].equals("W")){
                    count++;
                }

                if(!check && map[i][j].equals("B")){
                    count++;
                }

                check=!check;
            }
            check=!check;
        }

        return count;
    }

}
