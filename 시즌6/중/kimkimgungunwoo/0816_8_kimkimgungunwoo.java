import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(reader.readLine());
        String[] AB = reader.readLine().split(" ");
        int A = Integer.parseInt(AB[0]);
        int B = Integer.parseInt(AB[1]);

        Set<Point> xySet = new HashSet<>();
        for (int i = 0; i < N; i++) {
            String[] xy = reader.readLine().split(" ");
            int x = Integer.parseInt(xy[0]);
            int y = Integer.parseInt(xy[1]);
            xySet.add(new Point(x, y));
        }

        int cnt = 0;
        for (Point point : xySet) {
            int x = point.x;
            int y = point.y;
            
            if (xySet.contains(new Point(x + A, y)) &&
                xySet.contains(new Point(x, y + B)) &&
                xySet.contains(new Point(x + A, y + B))) {
                
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return 31 * x + y;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }
            Point point = (Point) obj;
            return x == point.x && y == point.y;
        }
    }
}