import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class minseok_1117_4 {
    public static void main(String[] args){
        List<Integer> list=new ArrayList<Integer>();
        Scanner scan =new Scanner(System.in);
        int N=scan.nextInt();
        for(int i=1;i<=N;i++){
            int num=scan.nextInt();
            list.add(i-num-1,i);
        }
        for(int i=0;i<N;i++){
            System.out.print(list.get(i)+" ");
        }
    }
}
