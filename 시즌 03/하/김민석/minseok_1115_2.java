import java.util.Arrays;
import java.util.Scanner;

public class minseok_1115_2 {
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int N=scan.nextInt();
        int []numAry=new int[N];
        for(int i=0;i<N;i++){
            numAry[i]= scan.nextInt();
        }
        Arrays.sort(numAry);
        System.out.print(numAry[0]+" ");
        for(int i=1;i<N;i++){
            if(numAry[i]!=numAry[i-1]){
                System.out.print(numAry[i]+" ");
            }
        }
    }
}

