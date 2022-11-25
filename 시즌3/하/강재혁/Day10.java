package 강재혁;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Day10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Coordinate[] co = new Coordinate[3];
        List<Double> d = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            co[i] = new Coordinate(sc.nextInt(), sc.nextInt());
        }

        if ((co[1].x - co[0].x) * (co[2].y - co[1].y)
                == (co[1].y - co[0].y) * (co[2].x - co[1].x)) { //기울기가 같을 경우(3점이 일직선 상에 있을 경우)
            System.out.println(-1);
        } else {
            for (int i = 0; i < co.length; i++) {       //피타고라스 사용
                double xLength = Math.pow(co[i].x - co[(i + 1) % 3].x, 2);
                double yLength = Math.pow(co[i].y - co[(i + 1) % 3].y, 2);

                d.add(Math.sqrt(xLength + yLength));
            }
            Collections.sort(d);
            System.out.println(2 * (d.get(2) - d.get(0)));
        }
    }
}

class Coordinate {
    int x, y;

    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
