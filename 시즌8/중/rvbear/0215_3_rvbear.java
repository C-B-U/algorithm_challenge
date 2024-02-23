import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));       // 버퍼 스트림을 통해 입력

        int N = Integer.parseInt(br.readLine());        // 입력값
        int[] DP = new int[N+1];                        // DP

        DP[0] = DP[1] = 0;                              // 초깃값 설정
        for(int i = 2; i <= N; i++) {
            DP[i] = DP[i - 1] + 1;                      // 1을 빼줌
            if(i % 2 == 0) DP[i] = Math.min(DP[i], DP[i / 2] + 1);      // 1을 뺀 값과 2로 나눈 값을 비교
            if(i % 3 == 0) DP[i] = Math.min(DP[i], DP[i / 3] + 1);      // 1을 뺀 값과 3으로 나눈 값을 비교
        }

        System.out.println(DP[N]);          // 해당 정수를 1로 만들기 위한 최솟값 출력
        br.close();                         // 입력 버퍼 스트림 닫아줌
    }
}