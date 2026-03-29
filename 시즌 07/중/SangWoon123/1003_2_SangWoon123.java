
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);

        int m=sc.nextInt();
        int n=sc.nextInt();

        boolean[] check = new boolean[n + 1];
        Arrays.fill(check, true);

        check[0]=false;
        check[1]=false;

        for(int i=2;i<=Math.sqrt(n);i++){
            if(!check[i]) continue;

            for(int j=i*i;j<=n;j+=i){
                check[j]=false;
            }
        }

        for(int i=m;i<n+1;i++){
            if(check[i]) System.out.println(i);
        }
    }



}
