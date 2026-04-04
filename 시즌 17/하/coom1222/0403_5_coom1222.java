package algorChal17;

import java.util.Scanner;

public class Day5 {
    public static void main(String[] args) {

        Scanner size = new Scanner(System.in);

        int duckIndex = 1;
        int gooseIndex = size.nextInt();

        while (true) {

            if (duckIndex == (gooseIndex - 1)){
                System.out.println("Duck");
                break;
            }
            duckIndex++;
            if (duckIndex == (gooseIndex - 1)) {
                System.out.println("Goose");
                break;
            }
            gooseIndex--;
        }
    }
}
