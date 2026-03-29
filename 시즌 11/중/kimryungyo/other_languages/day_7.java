// 자바가 재귀에서 느리다는 얘기를 듣긴 했지만 진짜 심각할 정도로 느리구나..

import java.util.Scanner;

public class Main {

    static void dfs(int N, int M, int[] sequence, boolean[] visited, int depth) {
        if (depth == M) {
            for (int num : sequence) {
                System.out.print(num + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                sequence[depth] = i;
                visited[i] = true;
                dfs(N, M, sequence, visited, depth + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[] visited = new boolean[N + 1];
        dfs(N, M, new int[M], visited, 0);
    }

}