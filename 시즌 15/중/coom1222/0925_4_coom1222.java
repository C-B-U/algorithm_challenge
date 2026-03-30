package AlgorithmChallenge15;

import java.util.Scanner;

public class Day4 {
    static int number_count;
    static int[] nums;
    static int[] operator;
    static int result_min = Integer.MAX_VALUE;
    static int result_max = Integer.MIN_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 첫째 줄에 수의 개수(2 ≤ N ≤ 11)가 주어진다.
        int number_count = scanner.nextInt();

        // 둘째 줄에 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100)
        nums = new int[number_count];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = scanner.nextInt();
        }

        // 셋째 줄에는 합이 N-1보다 크거나 같고, 4N보다 작거나 같은 네 개의 정수가 주어진다.
        // 이는 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수
        operator = new int[4];
        for (int i = 0; i < operator.length; i++) {
            operator[i] = scanner.nextInt();
        }
        dfs(1, nums[0]);

        // 최댓값 출력
        System.out.println(result_max);
        // 최솟값 출력
        System.out.println(result_min);
    }

    public static void dfs(int idx, int sum) {
        if (idx == number_count) {
            result_min = Math.min(result_min, sum);
            result_max = Math.max(result_max, sum);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (operator[i] == 0) continue;
            operator[i]--;
            switch (i) {
                case 0:
                    dfs(idx + 1, sum + nums[idx]);
                    break;
                case 1:
                    dfs(idx + 1, sum - nums[idx]);
                    break;
                case 2:
                    dfs(idx + 1, sum * nums[idx]);
                    break;
                case 3:
                    dfs(idx + 1, sum / nums[idx]);
                    break;
            }
            operator[i]++;
        }

    }
}

/*
N개의 수로 이루어진 수열 A1, A2, ..., AN이 있다.
수와 수 사이에 끼워넣을 수 있는 연산자가 주어진다. +, -, *, /(나눗셈) 4가지만 존재.
연산자의 개수는 N-1보다 많은 수도 있다.
모든 수 사이에는 연산자를 한 개 끼워넣어야 하며, 주어진 연산자를 모두 사용하지 않고 모든 수의 사이에 연산자를 끼워넣을 수도있다.
수와 수 사이에 연산자를 넣어 수식을 만들되, 주어진 수의 순서를 바꾸면 안된다.
1~6까지의 수열과 덧셈 3개 뺄셈 2개 곱센 1개 나눗셈 1개면 250가지의 수식이 완성된다.
연산자 우선순위는 무시, 나눗셈은 정수 나눗셈으로 몫만.
음수를 양수로 나눌 때는 양수로 바꾼 뒤 몫을 취하고 그 몫을 음수로 바꾼다.
N개의 수와 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하라.

 */
