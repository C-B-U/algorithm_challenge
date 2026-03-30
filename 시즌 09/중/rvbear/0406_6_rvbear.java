import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stb = new StringBuilder();

        int P = Integer.parseInt(br.readLine());

        for(int i = 0; i < P; i++) {
            String[] input = br.readLine().split(" ");
            int num = Integer.parseInt(input[1]);

            int a = 1, b = 1, count = 0;

            while(true) {
                int temp = (a + b) % num;
                a = b;
                b = temp;
                count++;

                if(a == 1 && b == 1) {
                    break;
                }
            }

            stb.append(input[0]).append(" ").append(count).append("\n");
        }

        System.out.print(stb);
    }
}
