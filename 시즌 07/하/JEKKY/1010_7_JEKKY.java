package Main;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int a=input.nextInt(),b=input.nextInt(),c=input.nextInt(),d=input.nextInt();
		if(a+d>b+c)System.out.println(a+d-b-c);
		else System.out.println(b+c-a-d);
		input.close();
	}
}