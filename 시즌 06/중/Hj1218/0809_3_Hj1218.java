import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int num[] = new int[n];
        for(int i=0;i<n;i++){
            num[i]=Integer.parseInt(br.readLine());
        }
        Arrays.sort(num);
        for(int i = n-1; i>=2 ; i-- ){
            if(num[i]<num[i-1]+num[i-2]){
                System.out.println(num[i]+num[i-1]+num[i-2]);
                return;
            }
        }
        System.out.println(-1);
    }
}