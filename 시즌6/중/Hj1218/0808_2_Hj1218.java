import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int fn = in.nextInt();
        long n = in.nextLong();
        long count=0;
        if(n==0){
            if(fn==1){
                count=0;
            }
            else{
                count=fn-1;
            }
        }
        else{
            if(fn==1){
                count=1+8*n-1;
            }
            if(fn==2){
                if(n%2==0){
                    count=2+8*(n/2)-1;
                }
                else{
                    count=2+8*(n/2)+6-1;
                }
            }
            if(fn==3) {
                count = 3 + 4 * n - 1;
            }
            if(fn==4){
                if(n%2==0){
                    count = 4 + 8*(n/2)-1;
                }
                else{
                    count=4+8*(n/2)+2-1;
                }
            }
            if(fn==5){
                count = 5 + 8*n - 1;
            }
        }
        System.out.println(count);
    }
}