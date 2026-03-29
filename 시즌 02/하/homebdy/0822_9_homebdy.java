import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

class homebdy_9 {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(bufferedReader.readLine());
        Double[] arr = new Double[num];

        for (int i = 0; i < num; i++) {
            arr[i] = Double.parseDouble(bufferedReader.readLine());
        }
        for (int i = 1; i < num; i++) {
            arr[i] = Math.max(arr[i-1]*arr[i], arr[i]);
        }
        Arrays.sort(arr, Collections.reverseOrder());
        System.out.printf("%.3f\n", arr[0]);
    }
}
