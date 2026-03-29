import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair>{                         // 각 점을 나타내는 클래스
    long x, y;

    public Pair(long _x, long _y) {
        x = _x; y = _y;
    }

    @Override
    public int compareTo(Pair p) {                              // 오버라이딩을 통해 정렬
        if(x == p.x) {
            return (y > p.y ? 1 : -1);
        }
        return (x > p.x ? 1 : -1);
    }
}
public class Main {
    static Pair[] pair;                                         // 클래스 배열
    public static boolean check(Pair p) {                       // 직사각형을 만드는데 필요한 점이 존재하는지 확인하는 메서드
        int start = 0, end = pair.length-1;
        while(start <= end) {                                   // 이분탐색 시작
            int mid = (start+end)/2;
            if(pair[mid].x == p.x && pair[mid].y == p.y) {      // 해당 점이 존재한다면 true를 return
                return true;
            }
            if(pair[mid].x == p.x) {
                if(pair[mid].y > p.y) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            } else if(pair[mid].x > p.x) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return false;                                           // 해당 점이 존재하지 않는다면 false를 return
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());                    // 점의 개수
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(stk.nextToken());                  // 만들고 싶은 직사각형의 가로 길이
        int b = Integer.parseInt(stk.nextToken());                  // 만들고 싶은 직사각형의 세로 길이

        pair = new Pair[n];
        for(int i = 0; i < n; i++) {
            stk = new StringTokenizer(br.readLine());
            pair[i] = new Pair(Long.parseLong(stk.nextToken()), Long.parseLong(stk.nextToken()));
        }

        Arrays.sort(pair);                                          // 이분탐색을 위해 배열 정렬

        long count = 0;                                             // 만들 수 있는 경우의 수
        for(int i = 0; i < n; i++) {
            Pair p1 = new Pair(pair[i].x + a, pair[i].y);       
            Pair p2 = new Pair(pair[i].x, pair[i].y + b);
            Pair p3 = new Pair(pair[i].x + a, pair[i].y + b);

            if(check(p1) && check(p2) && check(p3)) {               // 세 조건이 모두 만족한다면 직사각형을 만들 수 있음
                count++;
            }
        }

        System.out.println(count);                                  // 결과 출력
        br.close();
    }
}
