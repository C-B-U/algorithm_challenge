
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        int[] arr=new int[N];

        st=new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int max=arr[arr.length-1];


       int height=bs(0,max,arr,M);

        System.out.println(height);

    }

    private static int bs(int start, int end,int[] arr,int M) {

        while(start<=end){
            int mid=(start+end)/2;
            long sum=0;

            // 확인
            for(int i=0;i<arr.length;i++){
                if(arr[i]>mid){
                    sum+=arr[i]-mid;
                }
            }

            if(sum==M)  return mid;
            else if(sum<M) {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return end;
    }


}
