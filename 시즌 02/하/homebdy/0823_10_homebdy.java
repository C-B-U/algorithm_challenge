import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class homebdy_10 {

    static int[][] arr;
    static boolean[] visit;
    static int num, virusComputer;

    public static int DFS(int virus) {
        visit[virus] = true;
        for (int i = 1; i < num + 1; i++) {
            if (arr[virus][i] == 1 && !visit[i]) {
                virusComputer++;
                DFS(i);
            }
        }
        return virusComputer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        num = Integer.parseInt(bufferedReader.readLine());
        int network = Integer.parseInt(bufferedReader.readLine());
        arr = new int[num+1][num+1];
        visit = new boolean[num+1];

        for (int i = 0; i < network; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        System.out.println(DFS(1));
    }
}
