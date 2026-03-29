package Main;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int total = input.nextInt(), sec300=0, sec60=0, sec10=0; //a: 5min / b: 1min / c: 10sec
		if (total % 10 != 0) {
			System.out.println(-1);
		}
		else {
			if(total / 300 !=0) {
				sec300 = total/300;
				total-=sec300*300;
			}
			if(total / 60!=0) {
				sec60 = total/60;
				total-=sec60*60;
			}
			if(total / 10!=0) {
				sec10 = total/10;
				total-=sec10*10;
			}
			System.out.println(sec300+" "+sec60+" "+sec10);
		}
		input.close();
	}

}
