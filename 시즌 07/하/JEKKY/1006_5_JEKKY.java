package Main;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a, b;
		a = input.nextInt();
		b = input.nextInt();
		int factor = 1;
		if(a>b) {
			int num;
			num = a;
			a = b;
			b = num;
		}
		for(int i = 1; i < a+1; i++) {
			if(a%i == 0 && b%i == 0) {
				factor = i;
			}
		}
		int multiple = a*b/factor;
		System.out.println(factor);
		System.out.println(multiple);
		input.close();
	}
}