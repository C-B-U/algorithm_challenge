import java.util.Scanner;

public class kimhalin_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int digits = (int) (Math.log10(num) + 1);
        int result = 0;


        for(int i = (num - (digits * 9)); i < num; i++) {
            int number = i;
            int sum = 0;

            while(number != 0) {
                sum += number % 10;
                number /= 10;
            }

            // i 값과 각 자릿수 누적합이 같을 경우 (생성자를 찾았을 경우)
            if(sum + i == num) {
                result = i;
                break;
            }

        }

        System.out.println(result);
    }
}
