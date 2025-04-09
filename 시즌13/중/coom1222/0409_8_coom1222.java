import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Objects;
import java.util.StringTokenizer;

public class Main {
    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        //다른 인스턴스에 대해 같은 좌표를 비교하기 위해hashcode,equals 오버라이딩
        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
        
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        //점 개수 입력
        int N = Integer.parseInt(st.nextToken());
        //가로, 세로 길이 입력
        st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        
        //x,y 쌍을 이루는 hashset선언
        HashSet<Point> points = new HashSet<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            points.add(new Point(x, y));
        }

        int count = 0;
        for (Point point : points) {
            Point b = new Point(point.x + A, point.y);
            Point c = new Point(point.x, point.y + B);
            Point d = new Point(point.x + A, point.y + B);
            if (points.contains(b) && points.contains(c) && points.contains(d)) {
                count++;
            }
        }

        System.out.println(count);
    }
}
