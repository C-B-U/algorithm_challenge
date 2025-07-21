package Day1;

import java.util.ArrayList;
import java.util.Scanner;

public class Day2 {
    public static void main(String[] args) {
      /* 메모리 초과로 인한 백준 통과 X
      결과에선 최댓값만 출력하면 되는데, 수열과 최댓값을 배열까지 저장할 이유가 없다. 
      이로 인해 메모리 초과 발생
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> 수열 = new ArrayList<>();
        ArrayList<Integer> 최대값 = new ArrayList<>();

        int testCase = scanner.nextInt(); // 테스트 케이스의 개수

        for (int i = 1; i <= testCase; i++) {
            int n = scanner.nextInt();
            int maxValue = n; // 최대값을 저장하기 위한 변수

            수열.add(n);
            while (n != 1) {
                수열.add(n); // 현재 n 값을 수열에 추가
                if (n % 2 == 0) {
                    n = n / 2; // n이 짝수일 때
                } else {
                    n = (n * 3) + 1; // n이 홀수일 때
                }
                if (n > maxValue) {
                    maxValue = n; // 새로운 최대값이 발견되면 업데이트
                }
            }
            최대값.add(maxValue); // 최대값을 리스트에 추가
        }
        for(int i = 0; i < 최대값.size(); i++) {
            System.out.print(최대값.get(i) + "\n");
        }

        scanner.close();
      */

       Scanner scanner = new Scanner(System.in);

        int testCase = scanner.nextInt(); // 테스트 케이스의 개수

        for (int i = 1; i <= testCase; i++) {
            int n = scanner.nextInt();
            int maxValue = n; // 최대값을 저장하기 위한 변수

            while (n != 1) {
                if (n % 2 == 0) {
                    n = n / 2; // n이 짝수일 때
                } else {
                    n = (n * 3) + 1; // n이 홀수일 때
                }
                if (n > maxValue) {
                    maxValue = n; // 새로운 최대값이 발견되면 업데이트
                }
            }
            System.out.println(maxValue);
        }

        scanner.close();
    }
}
