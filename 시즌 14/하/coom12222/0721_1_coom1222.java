package Day1;

import java.util.Scanner;

public class Day1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 구매한 주스의 양 입력 ex) 9 9 9
        int A = scanner.nextInt(); // 오렌지
        int B = scanner.nextInt(); // 사과
        int C = scanner.nextInt(); // 파인애플

        // 칵테일 비율 입력 ex) 3 : 2 : 1
        int I = scanner.nextInt(); // 오렌지 비율
        int J = scanner.nextInt(); // 사과 비율
        int K = scanner.nextInt(); // 파인애플 비율

        // 각 주스로 만들 수 있는 칵테일의 개수 중 가장 작은 값을 구함
        // 예시를 따르면, 오렌지 3개, 사과 4.5개, 파일애플 9개 이므로 3개만 만들 수 있다.
        double 최대칵테일갯수 = Math.min(Math.min((double)A / I, (double)B / J), (double)C / K);

        // 사용된 주스의 양 계산
        double usedOrange = 최대칵테일갯수 * I;
        double usedApple = 최대칵테일갯수 * J;
        double usedPineapple = 최대칵테일갯수 * K;

        // 남은 주스의 양
        double remainedOrange = A - usedOrange;
        double remainedApple = B - usedApple;
        double remainedPineapple = C - usedPineapple;

        // 결과 출력, 소수점 6자리까지
        System.out.println(remainedOrange + " " + remainedApple + " " + remainedPineapple);

        scanner.close();

    }
}

/*
상근이와 지수는 마트에서 오렌지 주스, 사과 주스, 파인애플 주스를 구매했다. 그들은 인터넷에서 찾은 방법으로 무알콜 칵테일을 만들어 학교에서 팔려고 한다.
하지만, 칵테일을 만드는 방법을 찾기 전에 주스를 구매했기 때문에, 주스가 남을 수도 있다.

무알콜 칵테일을 만드는데 필요한 오렌지, 사과, 파인애플 주스의 비율과 구매한 주스의 양이 주어진다.
칵테일을 최대한 많이 만들었을 때, 각 주스가 얼만큼 남는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 구매한 오렌지, 사과, 파인애플 주스의 양 A, B, C가 주어진다. (1 ≤ A, B, C ≤ 500)

둘째 줄에 칵테일을 만드는데 필요한 각 주스의 비율 I, J, K가 주어진다. (1 ≤ I, J, K ≤ 50)

출력
첫째 줄에 칵테일을 최대한 많이 만들었을 때, 각 주스가 얼만큼 남는지를 공백으로 구분하여 출력한다. 정답과의 오차는 10-4까지 허용한다.
 */
