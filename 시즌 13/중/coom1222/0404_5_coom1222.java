import java.util.*;

public class Main {

    public static int maxValue = Integer.MIN_VALUE;	// 최댓값 (Integer의 가장 최솟값을 넣어줌)
    public static int minValue = Integer.MAX_VALUE;	// 최솟값 (Integer의 가장 최댓값을 넣어줌)
    public static int[] numArray;
    public static int[] operator = new int[4];
    public static int n;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        numArray = new int[n];

        for (int i = 0; i < n; i++) {
            numArray[i] = sc.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            operator[i] = sc.nextInt();
        }

        solution(numArray[0], 1);

        System.out.println(maxValue);
        System.out.println(minValue);

    }
    public static void solution(int num, int index) {

        if (index == n) {
            maxValue = Math.max(maxValue, num);
            minValue = Math.min(minValue, num);
            return;
        }

        for (int i = 0; i < 4; i++) {
            // 연산자 개수가 1개 이상인 경우
            if (operator[i] > 0) {

                // 해당 연산자를 1 감소시킨다.
                operator[i]--;

                switch (i) {

                    case 0: //더하기일 경우
                        solution(num + numArray[index], index + 1);
                        break;
                    case 1: //빼기일 경우
                        solution(num - numArray[index], index + 1);
                        break;
                    case 2: //곱하기일 경우
                        solution(num * numArray[index], index + 1);
                        break;
                    case 3: //나누기일 경우
                        solution(num / numArray[index], index + 1);
                        break;

                }
                // 재귀호출이 종료되면 다시 해당 연산자 개수를 복구한다.
                operator[i]++;
            }
        }
    }
}
