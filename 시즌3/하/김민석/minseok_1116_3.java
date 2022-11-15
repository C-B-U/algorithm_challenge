import java.util.Scanner;

public class minseok_1116_3 {
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        int X=scan.nextInt();
        int Y=scan.nextInt();
        int revX=Rev(X);
        int revY=Rev(Y);
        int sum=revX+revY;
        int ans=Rev(sum);
        System.out.print(ans);
    }
    public static int Rev(int num){
        int result=0;
        while(num!=0){
            result=result*10;
            result=result+num%10;
            num=num/10;
        }
        return result;
    }
}
