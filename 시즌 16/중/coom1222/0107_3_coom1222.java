import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력 1: 굴다리 길이 N
        int N = Integer.parseInt(br.readLine());
        // 입력 2: 가로등 개수 M
        int M = Integer.parseInt(br.readLine());

        // 입력 3: 가로등 좌표들
        int[] x = new int[M];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            x[i] = Integer.parseInt(st.nextToken());
        }

        // 최소 높이 구하기
        int height = 0;

        // Case 1: 0 ~ 첫 번째 가로등 사이 거리
        // 첫 가로등은 혼자서 0까지 비춰야 함
        height = Math.max(height, x[0]);

        // Case 2: 마지막 가로등 ~ N 사이 거리
        // 마지막 가로등은 혼자서 N까지 비춰야 함
        height = Math.max(height, N - x[M - 1]);

        // Case 3: 가로등 사이의 거리
        // 두 가로등이 서로 마주보며 비추므로 거리를 절반으로 나눔
        for (int i = 0; i < M - 1; i++) {
            int distance = x[i + 1] - x[i];
            
            // 거리가 홀수일 경우(예: 3), 1.5가 아닌 2가 되어야 하므로 올림 처리 필요
            // (distance + 1) / 2 는 정수 나눗셈에서 올림 효과를 냄
            int requiredHeight = (distance + 1) / 2;
            
            height = Math.max(height, requiredHeight);
        }

        System.out.println(height);
    }
}
