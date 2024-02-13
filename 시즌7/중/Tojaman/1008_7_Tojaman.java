import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int x1, y1, r1, x2, y2, r2;
        for (int i = 0; i < t; i++) {
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            r1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
            r2 = sc.nextInt();
            int dis2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

            if (x1 == x2 && y1 == y2) {
                if (r1 == r2) {
                    System.out.println(-1);
                } else
                    System.out.println(0);

            } else {
                if ((r1 + r2) * (r1 + r2) < dis2) {
                    System.out.println(0);
                } else if ((r1 + r2) * (r1 + r2) == dis2) {
                    System.out.println(1);
                } else {
                    if ((r1 - r2) * (r1 - r2) > dis2) {
                        System.out.println(0);
                    } else if ((r1 - r2) * (r1 - r2) == dis2) {
                        System.out.println(1);
                    } else
                        System.out.println(2);
                }

            }

        }

    }

}