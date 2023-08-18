import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stk = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(stk.nextToken());              // 수열의 크기
        long s = Long.parseLong(stk.nextToken());               // 만들어야하는 부분합
        long[] arr = new long[n+1];                             // 수열을 저장할 배열
        stk = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(stk.nextToken());
        }

        long sum = 0;                                           // 부분합
        int start = 0, end = 0, size = Integer.MAX_VALUE;       // 시작지점, 종료지점, 수열의 크기
        while(start <= n && end <= n) {
            if(s <= sum) {                                      // 만들어야하는 부분합보다 크거나 같을 경우 중
                size = Math.min(size, end-start);               // 가장 작은 수열의 크기를 구함
            }
            if(sum < s) {                                       // 부분합이 작을 경우 end 위치 옮겨서 더해줌
                sum += arr[end++];
            } else {                                            // 부분합이 클 경우 start 위치 옮겨서 빼줌
                sum -= arr[start++];
            }
        }

        if(size != Integer.MAX_VALUE) {                         // 만들어진 수열이 있을 경우
            bw.write(String.valueOf(size));                     // 해당 크기 출력
        } else {                                                // 만들어진 수열이 없을 경우
            bw.write(String.valueOf(0));                     // 0 출력
        }
        br.close(); bw.close();
    }
}