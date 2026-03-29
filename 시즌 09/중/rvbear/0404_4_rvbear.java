import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stb = new StringBuilder();

        int[] list = new int[1000001];

        for(int i = 2; i < 1000001; i++) {
            int index = i;
            list[index]++;
            for(int j = i + 1; j < 1000001; j++) {
                if((index + j) > 1000000) {
                    break;
                }
                index += j;
                list[index]++;
            }
        }

        while(true) {
            int N = Integer.parseInt(br.readLine());

            if(N == 0) {
                break;
            }

            stb.append(list[N]).append("\n");
        }

        System.out.print(stb);
    }
}