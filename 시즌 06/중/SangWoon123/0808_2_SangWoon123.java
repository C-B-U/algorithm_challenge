import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n=Long.parseLong(br.readLine());
        long m=Long.parseLong(br.readLine());

        if(n==1){
            System.out.println(8 * m);
        }else if(n==5){
            System.out.println(m*8+4);
        }else{
            long increment = (m % 2 == 1) ? (4 - n) : (n - 2);
            System.out.println(4 * m + 1 + increment);
        }

        // 참고: https://zoosso.tistory.com/135





    }

}