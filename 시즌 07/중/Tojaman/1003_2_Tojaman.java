import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];

//        에라토스테네스의 체 알고리즘 사용
//        에라토스테네스의 체란

        // 배열에 M ~ N까지 넣음
        for (int i = M; i <= N; i++) {
            arr[i] = i;
        }

        // 특정 수의 배수는 1, 특정 수, 자기 자신까지 최소 3개의 약수가 있으므로 소수가 아님
        // 2,3은 무조껀 소수이므로 i를 2부터 시작하면 index가 4인 값부터 소수 판별을 함
        for (int i = 2; i <= N; i++) {
            if (arr[i] == 1) continue;
            for (int j = i + i; j <= N; j += i) { // i의 배수
                arr[j] = 1;
            }
        }
        // 소수로 판별된 수만 출력
        for (int i = M; i <= N; i++) {
            if (arr[i] != 1) { // 소수일 경우
                bw.write(Integer.toString(arr[i]));
                bw.newLine();
            }
        }

//        - 수 하나한 소수를 판별하는 방법
//        for (int i = M; i < N; i++) {
//            int count = 0;
//            for (int j = 2; j < i; j++) {
//                if (i % j == 0)
//                    count++;
//                if (count > 0)
//                    break;
//            }
//            if (count <= 2) {
//                bw.write(Integer.toString(i));
//                bw.newLine();
//            }
//        }
        bw.flush();
        bw.close();
    }
}
