import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // "n개의 말이 참이다" 라는 문장이 n개가 등장했다면 그것이 답이다.
        int[] intArray = new int[N];

        // 배열에 저장
        for (int i = 0; i < N; i++) {
            intArray[i] = sc.nextInt();
        }

        // 일단 최댓값을 -1로 저장
        int max = -1;
        for (int j = 0; j <= N; j++) {  // N번을 반복하며 카운트를 셈
            int count = 0;
            for (int k = 0; k < N; k++) {   // 배열을 돌면서 j와 같은 값 카운트
                if (intArray[k] == j) {
                    count++;
                }
            }
            if (count == j) {   // j개가 참인 경우가 count개라면 일관성 성립
                max = Math.max(max, j);
            }
        }
        System.out.println(max);
    }
}
