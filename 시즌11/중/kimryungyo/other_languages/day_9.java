import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] graph = new int[128];
        for (int i = 0; i < 128; i++) {
            graph[i] = -1;
        }

        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" is ");
            int a = (int) input[0].charAt(0);
            int b = (int) input[1].charAt(0);
            graph[a] = b;
        }

        int M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            String[] input = br.readLine().split(" is ");
            int a = (int) input[0].charAt(0);
            int b = (int) input[1].charAt(0);

            boolean[] visited = new boolean[128];
            visited[a] = true;

            while (a != b) {
                a = graph[a];
                if (a == -1) break;
                if (visited[a]) break;
                visited[a] = true;
            }

            if (a == b) {
                System.out.println("T");
            } else {
                System.out.println("F");
            }
        }
    }
}