package recipt;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int total = input.nextInt(); 
		int n = input.nextInt();
		int price = 0, num = 0, table = 0;
		for (int i=0; i<n; i++) {
			price = input.nextInt();
			num = input.nextInt();
			table = price*num;
			total-=table;
			table = 0;
		}
		if (total == 0) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		input.close();
	}
}
