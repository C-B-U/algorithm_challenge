package 강재혁;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Day05 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] A = new int[10];
        int num = scanner.nextInt();
        int count = 0;

        while (num > 0) {
            int temp = num % 10;
            num = num / 10;

            if (temp == 6 || temp == 9) {   //6,9가 들어오면 count++
                count++;
            }
            if (count == 2) {   //count가 2면 count를 0으로 만들어주고 continue
                count=0;
                continue;
            }
            if (temp == 9) {        //9일 경우 6으로 생각
                A[6]++;
            } else {
                A[temp]++;
            }
        }
        Arrays.sort(A);
        System.out.println(A[9]);
    }
}
