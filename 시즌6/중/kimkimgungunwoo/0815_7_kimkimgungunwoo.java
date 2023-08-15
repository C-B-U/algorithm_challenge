import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
public class Main{

    public static void main(String args[]) throws IOException{
        BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
        int N,L,i,index,answer=0,tempindex=0;
        double start,end;
        String[] input=reader.readLine().split(" ");
        N=Integer.parseInt(input[0]);
        L=Integer.parseInt(input[1]);
        int[] inputlist=new int[N];
        input=reader.readLine().split(" ");
        for(i=0;i<N;i++){
            inputlist[i]=Integer.parseInt(input[i]);
        }
        Arrays.sort(inputlist);
        index=0;
        while(true){
            start=inputlist[index]-0.5;
            end=start+L;
            for(i=index;i<N;i++){
                if(inputlist[i]>end){
                    index=i;
                    answer+=1;
                    break;
                }
            }
            if(i==N){
                answer+=1;
                break;
            }
            
        }
        System.out.println(answer);

    }
}
