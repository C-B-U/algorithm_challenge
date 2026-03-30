
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] dice = {0,0,0,0,0,0};
    public static void main(String [] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int rowSize = Integer.parseInt(st.nextToken());
        int colSize = Integer.parseInt(st.nextToken());
        int diceRow = Integer.parseInt(st.nextToken());
        int diceCol = Integer.parseInt(st.nextToken());
        int orderCount = Integer.parseInt(st.nextToken());
        int[][] map = new int[rowSize][];
        for (int i = 0; i < rowSize; i++) {
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        int[] order = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (int o : order) {
            switch (o) {
                case 1:
                    if(diceCol == colSize -1) {
                        continue;
                    }
                    diceCol++;
                    goEast();
                    break;
                case 2:
                    if(diceCol == 0) {
                        continue;
                    }
                    diceCol--;
                    goWest();
                    break;
                case 3:
                    if(diceRow == 0) {
                        continue;
                    }
                    diceRow--;
                    goNorth();
                    break;

                case 4:
                    if(diceRow == rowSize -1) {
                        continue;
                    }
                    diceRow++;
                    goSouth();
                    break;

            }
            if(map[diceRow][diceCol] == 0) {
                map[diceRow][diceCol] = getFloor();
            }else {
                dice[2] = map[diceRow][diceCol];
                map[diceRow][diceCol] = 0;
            }
            sb.append(getceiling()).append("\n");
        }


        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }
    private static void goEast() {
        int temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = temp;
    }
    private static void goWest() {
        int temp = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    private static void goSouth() {
        int temp = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[0];
        dice[0] = temp;
    }
    private static void goNorth() {
        int temp = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[5];
        dice[5] = temp;
    }
    private static int getFloor() {
        return dice[2];
    }
    private static int getceiling() {
        return dice[5];
    }
}
