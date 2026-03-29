import java.io.*;
import java.util.*;

class Robot implements Comparable<Robot> {
    int index;              // 로봇이 나타나는 순서
    double t;               // 로봇에 도달하는 시간 = 로봇과의 거리 / 미사일 속도

    public Robot(int _index, double _t) {
        index = _index; t = _t;
    }

    @Override
    public int compareTo(Robot b) {     // 오버라이딩을 통해 배열 정렬
        if(t == b.t) {                  // 로봇에 도달하는 시간이 같다면 먼저 들어온 순서대로 정렬
            return index > b.index ? 1 : (index < b.index ? -1 : 0);
        }                               // 로봇에 도달하는 시간이 다르다면 짧은 순서대로 정렬
        return t > b.t ? 1 : (t < b.t ? -1 : 0);
    }
}
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Robot[] robots = new Robot[n];                                 // 로봇을 저장할 배열

        for(int i = 0; i < n; i++) {                                   // 입력 여부 확인
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(stk.nextToken());                 // x 좌표
            int y = Integer.parseInt(stk.nextToken());                 // y 좌표
            int v = Integer.parseInt(stk.nextToken());                 // 미사일 속도
            double d = (Math.sqrt(x*x + y*y)) / v;                     // 로봇까지 걸리는 시간 계산
            robots[i] = new Robot(i+1, d);                             // 배열에 저장
        }

        Arrays.sort(robots);                                           // 배열 정렬

        for(Robot r : robots) {                                        // 배열에 저장된 순서대로 로봇의 인덱스를 출력
            System.out.println(r.index);
        }
        br.close();
    }
}