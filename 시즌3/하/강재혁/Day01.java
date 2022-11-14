package 시즌3.하.강재혁;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Day01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<Integer> white = new ArrayList<>();
        List<Integer> black = new ArrayList<>();

        white.add(sc.nextInt());
        black.add(sc.nextInt());
        sc.nextLine();
        black.add(sc.nextInt());
        white.add(sc.nextInt());
        sc.nextLine();
        white.add(sc.nextInt());
        black.add(sc.nextInt());

        int wMin= Collections.min(white);
        int bMin= Collections.min(black);

        int min=0;
        if(wMin<bMin){
            min=wMin;
        } else {
            min=bMin;
        }

        if (wMin != bMin) {
            System.out.println(min*2+1);
        } else {
            System.out.println(min*2);
        }
    }
}
