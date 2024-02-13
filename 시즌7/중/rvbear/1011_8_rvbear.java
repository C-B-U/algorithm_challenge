import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));           // 버퍼 스트림을 통해 입력
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(stk.nextToken());              // 나무의 수
        int M = Integer.parseInt(stk.nextToken());              // 나무의 길이

        long[] trees = new long[N];                             // 각 나무의 길이를 저장할 배열
        stk = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            trees[i] = Long.parseLong(stk.nextToken());

        Arrays.sort(trees);                                     // 오름차순 정렬

        long min = 0, max = trees[N-1];                         // 최솟값, 최댓값 설정
        while(min <= max) {                                     // 이분탐색 시작
            long mid = (min + max) / 2;                         // 중간값 설정
            long sum = 0;
            for(long Height : trees)                            // 중간값보다 나무의 길이가 길 경우 잘라낸 값을 sum에 더함
                if(mid < Height) sum += (Height - mid);

            if(sum >= M) min = mid + 1;                         // sum의 크기가 M보다 클 경우 최솟값의 위치 옮겨줌
            else max = mid - 1;                                 // sum의 크기가 작거나 같을 경우 최댓값의 위치 옮겨줌
        }

        System.out.println((min + max) / 2);                    // 결과값을 출력
        br.close();                                             // 입력 버퍼 스트림 닫아줌
    }
}