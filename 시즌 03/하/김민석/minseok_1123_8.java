import java.util.Scanner;

public class minseok_1123_8 {
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        int N=scan.nextInt();
        for(int i=0;i<N;i++){
            int number1= scan.nextInt();
            int number2= scan.nextInt();
            System.out.println(lcm(number1,number2)+" "+gdc(number1,number2));
        }
    }
    public static int gdc(int num1, int num2){
        if(num1<num2){
            int tmp=num1;
            num1=num2;
            num2=tmp;
        }
        while(num2!=0){
            int r=num1%num2;
            num1=num2;
            num2=r;
        }
        return num1;
    }
    public static int lcm(int num1,int num2){
        return (num1*num2)/gdc(num1,num2);
    }
}
