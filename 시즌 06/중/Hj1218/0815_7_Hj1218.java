import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int l = in.nextInt();
        int []num = new int[1001];
        for(int i=0;i<n;i++){
            int a = in.nextInt();
            num[a]=1;
        }
        int count=0;
        for(int i=1;i<=1000;i++){
            if(num[i]!=0){
                i+=l-1;
                count++;
            }
        }
        System.out.println(count);
    }
}