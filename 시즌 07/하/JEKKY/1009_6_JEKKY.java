package Main;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int num = input.nextInt(), n = 1, add = 0, times = 1;
		while(true) {
			if(num<=n) {
				System.out.println(times);
				break;
			}
			else {
				add += 6;
				n +=add;
				times += 1;
			}
		}
		input.close();
	}
}