import java.util.Scanner;

class homebdy_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int result = 0;
        for (int i=0; i<num; i++) {
            int k = i;
            int sum = i;
            while(k > 0) {
                sum += k%10;
                k /= 10;
            }
            if (sum == num) {
                result = i;
                break;
            }
        }
        System.out.println(result);
    }
}
