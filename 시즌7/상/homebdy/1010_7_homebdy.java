import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String [] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] height = new int[n];
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            height[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < n - 1; i++) {
            result[i] = result[i] + 1;
            result[i + 1] = result[i + 1] + 1;
            double incline = height[i + 1] - height[i];
            for (int j = i + 2; j < n; j++) {
                double next = (double) (height[j] - height[i]) / (j - i);
                if (next > incline) {
                    incline = next;
                    result[i] += 1;
                    result[j] += 1;
                }
            }
        }

        System.out.println(Arrays.stream(result).max().orElse(0));
    }
}
