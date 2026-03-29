
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input=br.readLine().split(" ");
        int x=Integer.parseInt(input[0]);
        int y=Integer.parseInt(input[1]);

        int gcd = gcd(x, y);

        System.out.println(x+y-gcd);


    }

    private static int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }


}