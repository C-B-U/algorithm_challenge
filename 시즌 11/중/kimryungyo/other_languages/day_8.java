import java.util.Stack;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String nums_string = br.readLine();
        String[] nums_str = nums_string.split(" ");
        int[] stones = new int[N];;
        for (int i = 0; i < nums_str.length; i++) {
            stones[i] = Integer.parseInt(nums_str[i]);
        }

        int S = Integer.parseInt(br.readLine());

        boolean[] visited = new boolean[N];
        visited[S - 1] = true;

        int next, jump, count = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(S - 1);

        while (!stack.isEmpty()) {
            int pos = stack.pop();
            count++;

            jump = stones[pos];

            next = pos - jump;
            if (next >= 0 && next < N && !visited[next]) {
                visited[next] = true;
                stack.push(next);
            }

            next = pos + jump;
            if (next >= 0 && next < N && !visited[next]) {
                visited[next] = true;
                stack.push(next);
            }

        }

        System.out.println(count);
    }
}