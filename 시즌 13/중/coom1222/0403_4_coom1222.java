import java.util.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		//다친 손가락
		int n = sc.nextInt();
		
		//다친 손가락 사용 가능 횟수
		long count = sc.nextLong();
		
		long answer = 0;
		if(1<=count) {
			answer+=5; 										//첫 번째 
			if(n!=1 && n!=5) answer+=((count-1)*4);			//중간
			else if(n==1 || n==5) answer+=((count-1)*4*2);
			
			if(n==1) answer+=3;								//마지막
			else if(n==5) answer+=7;
			else if(count%2==0) answer+=(n-2); 		
			else if(count%2!=0) answer+=(4-n);
		}
		else {
			answer+=(n-1);
		}
	
		//출력
		System.out.println(answer);
	}
}
