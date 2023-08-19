import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stk.nextToken());              // 물 새는 곳의 개수
        int l = Integer.parseInt(stk.nextToken());              // 테이프의 길이
        int[] arr = new int[n];                                 // 물 새는 곳을 저장할 배열

        stk = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(stk.nextToken());
        }

        Arrays.sort(arr);                                       // 배열을 정렬

        int count = 1, temp = arr[0] + l - 1;                   // 테이프의 개수와 테이프로 붙일 수 있는 마지막 부분
        for(int i = 0; i < n; i++) {
            if(temp >= arr[i]) continue;                        // 테이프로 붙일 수 있는 부분이라면 continue
            count++;                                            // 아니라면 count를 증가한 뒤
            temp = arr[i] + l - 1;                              // 테이프로 붙일 수 있는 부분을 다시 설정
        }

        System.out.println(count);                              // count 출력
        br.close();
    }
}