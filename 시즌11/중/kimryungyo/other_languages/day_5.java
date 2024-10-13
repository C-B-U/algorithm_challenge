import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String nums_str = br.readLine();
        String[] nums = nums_str.split(" ");

        int[] counts = new int[50001];
        for (String num : nums) {
            counts[Integer.parseInt(num)] += 1;
        }

        int max_count = 0;
        for (int i = 0; i < 50001; i++) {
            if (counts[i] > max_count) {
                max_count = counts[i];
            }
        }

        System.out.println(max_count);
    }
}