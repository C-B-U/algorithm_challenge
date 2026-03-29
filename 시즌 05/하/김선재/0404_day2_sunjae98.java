import javax.imageio.IIOException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.ArrayIndexOutOfBoundsException;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        if (n >= 1) {
            int[] arr = new int[n + 1];

            arr[0] = 0;
            arr[1] = 1;

            for (int i = 2; i < n + 1; i++) {
                arr[i] = arr[i - 1] + arr[i - 2];
            }

            System.out.print(arr[n]);

            br.close();
        } else {
            System.out.print(0);
        }
    }
}