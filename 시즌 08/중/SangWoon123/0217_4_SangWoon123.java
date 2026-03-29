
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n= Integer.parseInt(br.readLine());

        int[] result=new int[n];

        if(n%2==1){
            System.out.println(1);
            return;
        }else{
            for(int i=0;i<n;i++){
                st=new StringTokenizer(br.readLine());
                int a=Integer.parseInt(st.nextToken());
                int b=Integer.parseInt(st.nextToken());

                int num=a-b;

                result[i]=num;
            }
            Arrays.sort(result);
            System.out.println(Math.abs(result[n/2]-result[n/2-1])+1);
        }




    }
}