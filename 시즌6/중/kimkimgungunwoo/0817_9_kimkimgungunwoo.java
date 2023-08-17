import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int findGCD(int s, int big) {
        int a=s,b=big;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); 
        String[] input=reader.readLine().split(" ");
        int x=Integer.parseInt(input[0]),y=Integer.parseInt(input[1]),answer;
        if(x==y){
            answer=x;
        }
        else{
            int gcd=findGCD((x<y)?x:y, (x<y)?y:x);
            if(gcd==1){
                answer=x+y-1;
            }
            else{
                
                answer=x+y-gcd;
            }
        }
        System.out.println(answer);


    }
}
