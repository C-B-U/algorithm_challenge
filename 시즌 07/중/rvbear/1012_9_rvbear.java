import java.io.*;
import java.util.*;

public class Main {
    static int n, k;                                    // 수빈이가 있는 위치, 동생이 있는 위치
    static int[] check = new int[100001];               // 시간 저장을 위한 배열
    public static void bfs (int start) {                // bfs 탐색
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        check[start] = 1;

        while(!queue.isEmpty()) {
            int temp = queue.poll();

            for(int i = 0; i < 3; i++) {
                int next;
                if(i == 0) {                            // 위치 + 1
                    next = temp + 1;
                } else if (i == 1) {                    // 위치 - 1
                    next = temp - 1;
                } else {                                // 위치 * 2
                    next = temp * 2;
                }
                if(next == k) {                         // 움직였을 때 동생이 있는 위치에 다다르면 탐색 종료
                    System.out.println(check[temp]);
                    return;
                }
                // 배열의 안에 존재하며 해당 위치로 간 적이 없을 경우
                if(next >= 0 && next < check.length && check[next] == 0) {
                    queue.add(next);
                    check[next] = check[temp] + 1;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));       // 버퍼 스트림을 통해 입력
        StringTokenizer stk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(stk.nextToken());          // 수빈이의 위치 입력
        k = Integer.parseInt(stk.nextToken());          // 동생의 위치 입력

        if(n == k) {                                    // 수빈이와 동생의 위치가 같을 경우
            System.out.println(0);
        } else {                                        // 다를 경우
            bfs(n);
        }
        br.close();                                     // 입력 버퍼 스트림 닫아줌
    }
}