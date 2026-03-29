import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // N 입력
        int N = Integer.parseInt(br.readLine());
        
        // 실수들을 저장할 배열
        double[] arr = new double[N];
        
        for (int i = 0; i < N; i++) {
            arr[i] = Double.parseDouble(br.readLine());
        }
        
        // 최댓값을 저장할 변수 (초기값은 첫 번째 원소)
        double maxProduct = arr[0];
        
        // 두 번째 원소부터 순회하며 누적 곱 계산
        for (int i = 1; i < N; i++) {
            // "이전까지의 누적 곱 * 현재 값" vs "현재 값" 중 더 큰 것을 선택
            // 즉, 이전 누적 곱이 1보다 작아서 현재 값을 깎아먹는다면 버리고 새로 시작
            arr[i] = Math.max(arr[i], arr[i-1] * arr[i]);
            
            // 전체 최댓값 갱신
            maxProduct = Math.max(maxProduct, arr[i]);
        }
        
        // 소수점 셋째 자리까지 출력 (String.format 이용 - 반올림 자동 처리)
        System.out.printf("%.3f", maxProduct);
    }
}
