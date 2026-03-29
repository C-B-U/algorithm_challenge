import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int s = in.nextInt();
        int []num = new int[n+1];
        for(int i=0;i<n;i++){
            num[i]=in.nextInt();
        }
        int min = Integer.MAX_VALUE;
        int start = 0;
        int end = 0;
        int sum = 0;
        while(start<=n&&end<=n){
            if(sum<s){
                sum+=num[end];
                end++;
            }
            else{
                min = Math.min(min,end-start);
                sum-=num[start];
                start++;
            }
        }
        if(min==Integer.MAX_VALUE){
            System.out.println(0);
        }
        else{
            System.out.println(min);
        }
    }
}