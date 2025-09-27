/* 슬라이딩 윈도우 인줄 모르고 푼 코드
public class Day1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 애플파이의 개수 N과 먹을 개수 K 공백으로 입력받기
        int N = scanner.nextInt();  // 5
        int K = scanner.nextInt();  // 3
        int maxSum = 0;

        // 애플파이의 맛있는 정도를 애플파이의 수 만큼 입력받기
        int[]Pies = new int[N];
        for (int i = 0; i < N; i++) {
            Pies[i] = scanner.nextInt();  // 2 4 5 1 3
        }

        // K개의 연속된 애플파이의 맛의 합의 최댓값 구하기
        // 리스트를 돌며 최댓값 갱신
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < K; j++) {
                int index = (i + j) % N; // 원형 배열처럼 동작하도록 인덱스가 배열 길이를 넘어가도 % 연산으로 회복
                sum += Pies[index];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        System.out.println(maxSum);

    }
}
*/

// 슬라이딩 윈도우 적용.. 문제에 슬라이딩 윈도우라고 적혀있는데 원형배열로 생각한..
public class Day1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 애플파이의 개수 N과 먹을 개수 K 공백으로 입력받기
        int N = scanner.nextInt();  // 5
        int K = scanner.nextInt();  // 3
        int maxSum = 0;

        int[] Pies = new int[N];
        for (int i = 0; i < N; i++) {
            Pies[i] = scanner.nextInt();
        }
        
        // 1. 원형 배열 문제를 해결하기 위해 배열을 확장 (기존 배열 뒤에 맨 앞 K-1개를 이어붙임)
        int[] extendedPies = new int[N + K - 1];
        for (int i = 0; i < N; i++) {
            extendedPies[i] = Pies[i];
        }
        for (int i = 0; i < K - 1; i++) {
            extendedPies[N + i] = Pies[i];
        }

        // 2. 첫 번째 윈도우(0번부터 K-1번까지)의 합을 계산
        int currentSum = 0; 
        for (int i = 0; i < K; i++) {
            currentSum += extendedPies[i];
        }
        int maxSum = currentSum;

        // 3. 슬라이딩 윈도우 진행 (K번째 요소부터 확장된 배열의 끝까지)
        for (int i = K; i < extendedPies.length; i++) {
            // 맨 왼쪽 값(i-K)을 빼고, 새로 들어온 오른쪽 값(i)을 더함
            currentSum = currentSum - extendedPies[i - K] + extendedPies[i];

            // maxSum 갱신
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        System.out.println(maxSum);
        scanner.close();
    }
}
