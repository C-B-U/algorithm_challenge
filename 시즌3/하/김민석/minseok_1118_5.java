import java.util.Arrays;
import java.util.Scanner;

public class minseok_1118_5 {
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        int N=scan.nextInt();
        int ary[]=new int[11];
        while(N!=0) {
            ary[N % 10]++;
            N = N / 10;
        }
        if((ary[6]+ary[9])%2==0){
            int tmp=ary[6];
            ary[6]=(ary[6]+ary[9])/2;
            ary[9]=(tmp+ary[9])/2;
        }else{
            int tmp=ary[6];
            ary[6]=(ary[6]+ary[9])/2+1;
            ary[9]=(tmp+ary[9])/2+1;
        }
        Arrays.sort(ary);
        System.out.print(ary[10]);
    }
}
