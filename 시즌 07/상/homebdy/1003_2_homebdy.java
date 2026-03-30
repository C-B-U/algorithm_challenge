import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[] cubes;
    static boolean flag;
    static int result;

    public static void main(String [] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int length = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());

        n = Integer.parseInt(br.readLine());
        cubes = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken());
            cubes[index] = Integer.parseInt(st.nextToken());
        }
        
        divide(length, width, height);
        if (flag) {
            System.out.println(result);
        }
        else {
            System.out.println(-1);
        }
    }

    public static void divide(int length, int width, int height) {
        if (length == 0 || width == 0 || height == 0) {
            return;
        }
        flag = false;
        int cubeLen = 0;
        for (int i = cubes.length - 1; i >= 0; i--) {
            if (cubes[i] == 0) {
                continue;
            }
            cubeLen = 1 << i;
            if (length >= cubeLen && width >= cubeLen && height >= cubeLen) {
                result++;
                cubes[i]--;
                flag = true;
                break;
            }
        }
        if (!flag) {
            return;
        }
        divide(cubeLen , width - cubeLen, cubeLen);
        divide(length - cubeLen, width, cubeLen);
        divide(length, width, height - cubeLen);
    }
}