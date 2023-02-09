
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int treeSize;
    static long answer;
    static long[][][][] dpArr = new long[11][101][101][101];
    static long[][] combiDp = new long[101][101];

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        treeSize = Integer.parseInt(st.nextToken());
        int redCount = Integer.parseInt(st.nextToken());
        int greenCount = Integer.parseInt(st.nextToken());
        int blueCount = Integer.parseInt(st.nextToken());


        answer = dp(treeSize, redCount, greenCount, blueCount);
        sb.append(answer);
        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }

    public static long dp(int level, int red, int green, int blue) {
        if (red < 0 || green < 0 || blue < 0) return 0;
        if (level <= 0) return 1;
        if (dpArr[level][red][green][blue] != 0) return dpArr[level][red][green][blue];
        //1개만 쓸 떄
        //빨
        dpArr[level][red][green][blue] += dp(level - 1, red - level, green, blue);
        //초
        dpArr[level][red][green][blue] += dp(level - 1, red, green - level, blue);
        //파
        dpArr[level][red][green][blue] += dp(level - 1, red, green, blue - level);

        //2개 쓸 때
        if (level % 2 == 0) {
            int count = level / 2;
            long caseCount = getCombi(level, count, 2);
            // 빨파
            dpArr[level][red][green][blue] += caseCount * dp(level - 1, red - count, green, blue - count);
            // 빨초
            dpArr[level][red][green][blue] += caseCount * dp(level - 1, red - count, green - count, blue);
            // 초파
            dpArr[level][red][green][blue] += caseCount * dp(level - 1, red, green - count, blue - count);

        }

        //3개 다 쓸때
        //빨초파 나는 반초파
        if (level % 3 == 0) {
            int count = level / 3;
            long caseCount = getCombi(level, count, 3);
            dpArr[level][red][green][blue] += caseCount * dp(level - 1, red - count, green - count, blue - count);

        }

        return dpArr[level][red][green][blue];
    }

    static long getCombi(int number, int count, int size) {
        if (combiDp[number][count] != 0) return combiDp[number][count];
        long result = 1;
        for (int i = 1; i <= number; i++) {
            result *= i;
        }
        for (int i = 1; i <= count; i++) {
            for (int j = 0; j < size; j++) {
                result /= i;
            }
        }
        combiDp[number][count] = result;
        return result;
    }
}
