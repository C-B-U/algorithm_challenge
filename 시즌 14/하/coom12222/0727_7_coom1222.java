/* 틀린 케이스
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int H = sc.nextInt();
    int M = sc.nextInt();
    if (H==0){
      if (M > 45) {
      M -= 45;
      System.out.println(H + ' ' + M);
      } else if (M < 45) {
      H = 23;
      M += 15;
      System.out.println(N + ' ' + M);
    } 
    } else {
      if (M > 45) {
      M -= 45;
      System.out.println(H + ' ' + M);
      } else if (M < 45) {
        M += 15;
        System.out.println(H-1 + ' ' + M);
        } 
      }

  sc.close();
  }
}
*/
// 아마 전체적인 시간을 60분 기준으로 안잡아서 위에서는 오답처리를 한 것 같다. 
// 작성하다 이제서야 알아챘는데, 정확히 45분인 경우에 처리를 안했다.
// 시간계산하는 방법은 그냥 외우는게 편할지도.. 전체를 60으로 생각하기
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt(); 
		int M = sc.nextInt(); 

        if (M < 45) {
            H--;
            M = 60 - (45-M);
            if (H<0){
                H = 23;
            }
            System.out.println(H + " " + M);
        }
        else {
            System.out.println(H + " " + (M-45));
        }
        sc.close();
	}

}
