import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class homeby_7 {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(bufferedReader.readLine());

        for (int i = 0; i < T; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
            int N = Integer.parseInt(stringTokenizer.nextToken());
            int M = Integer.parseInt(stringTokenizer.nextToken());
            int result = 0;
            int[][] arr= new int[N+1][N+1];
            for (int j = 0; j < M; j++) {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
                int A = Integer.parseInt(stringTokenizer.nextToken());
                int B = Integer.parseInt(stringTokenizer.nextToken());
                arr[A][B] = 1;
                arr[B][A] = 1;
            }
            //BFS
            Queue<Integer> queue = new LinkedList<>();
            boolean[] visit = new boolean[N+1];
            queue.add(1);
            visit[1] = true;
            while (!queue.isEmpty()){
                result++;
                int value = queue.poll();
                for (int j = 1; j < N+1; j++) {
                    if (arr[value][j] == 1 && !visit[j]) {
                        visit[j] = true;
                        queue.add(j);
                    }
                }
            }
            System.out.println(result-1);
        }
    }
}
