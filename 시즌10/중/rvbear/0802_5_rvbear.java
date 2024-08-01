import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int W = Integer.parseInt(input[0]);
        int H = Integer.parseInt(input[1]);
        int N = Integer.parseInt(input[2]);

        double slope = (double)H / (double)W;

        double totalLength = 0;
        for (int i = 1; i <= N / 2; i++) {
            double x = (double) i * W / N;
            double y = slope * x;
            totalLength += H - 2 * y;
        }

        System.out.println(totalLength * 2);
        br.close();
    }
}
