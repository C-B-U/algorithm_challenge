import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long x = in.nextLong();
        long y = in.nextLong();
        System.out.println(x+y-gcd(x,y));
    }
    static long gcd(long x, long y){
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }
}