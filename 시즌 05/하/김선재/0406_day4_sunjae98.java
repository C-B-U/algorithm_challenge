import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String n = scan.next();

        int Nsize = n.length();
        int[] needSet = new int[10];
        int temp = 0;
        int max = 0;


        for (int i = 0; i < Nsize; i++) {
            temp = n.charAt(i) - '0';
            needSet[temp]++;
        }

        int k = (needSet[6] + needSet[9]);

        if (k % 2 == 0) {
            needSet[6] = k / 2;
            needSet[9] = k / 2;
        } else {
            needSet[6] = k / 2 + 1;
            needSet[9] = k / 2 + 1;
        }

        for (int i : needSet) {
            max = Math.max(max, i);
        }
        System.out.println(max);

    }
}