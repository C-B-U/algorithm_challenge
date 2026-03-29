package 강재혁;

import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Day03 {
    public static void main(String[] args) throws Exception{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] input = bf.readLine().split(" ");

        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);

        int result = reverse(x) + reverse(y);
        System.out.println(reverse(result));
        bf.close();
    }

    private static int reverse(int number) {
        int reverseNumber = 0;
        while (number != 0) {
            reverseNumber = reverseNumber * 10 + number % 10;
            number /= 10;
        }
        return reverseNumber;
    }
}
