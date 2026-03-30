package 강재혁;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Day04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> student = new ArrayList<>();

        int N = sc.nextInt();
        sc.nextLine();
        for (int i = 1;  i <= N; i++ ) {
            student.add(i);
        }

        for (int i = 0; i < N; i++) {
            int number = sc.nextInt();
            int studentNumber = student.get(i);
            student.remove(i);
            student.add(i - number, studentNumber);
        }
        for (Integer i : student) {
            System.out.print(i + " ");
        }
    }
}
