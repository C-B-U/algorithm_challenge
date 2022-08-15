import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class homebdy_4 {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.parseInt(bufferedReader.readLine());

        long[] dist = new long[num-1];
        long[] cost = new long[num];

        // 도시 간 거리 입력
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
        for (int i = 0; i < num-1; i++) {
            dist[i] = Long.parseLong(stringTokenizer.nextToken());
        }
        // 기름 가격
        stringTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
        for (int i = 0; i < num; i++) {
            cost[i] = Long.parseLong(stringTokenizer.nextToken());
        }

        long total = dist[0]*cost[0];
        long min = cost[0];
        for (int i = 1; i < num-1; i++) {
            if (cost[i] < min) {
                min = cost[i];
            }
            total += dist[i]*min;
        }
        System.out.println(total);
    }
}
