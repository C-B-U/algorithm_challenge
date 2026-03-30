import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());

        if(num < 100) {
            System.out.println(num);
        } else {
            int count = 99;
            for(int i = 100; i < num + 1; i++) {
                int hun = i / 100;
                int ten = (i / 10) % 10;
                int one = i % 10;

                if((hun - ten) == (ten - one)) {
                    count++;
                }
            }

            System.out.println(count);
        }
        
        br.close();
    }
}