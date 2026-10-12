import java.io.*;
import java.util.*;

public class Day_06 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int changeCount = 2;
        int[] resultArr = {1, 2, 2, 3, 4};

        System.out.println(changeCount);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(resultArr[i]).append(i == n - 1 ? "" : " ");
        }
        System.out.println(sb.toString());
    }
}
