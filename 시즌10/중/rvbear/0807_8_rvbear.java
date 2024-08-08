import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static HashMap<String, Integer> seniorList;
    static ArrayList<Senior>[][] arr;

    static class Senior {
        String name;
        int value;

        public Senior(String name, int price) {
            this.name = name;
            this.value = price;
        }
    }

    public static String solve() {
        StringBuilder stb = new StringBuilder();

        int ans = 0, count = 0;
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 7; j++) {
                boolean flag = false;
                List<Senior> promises = arr[i][j];

                for(Senior promise : promises) {
                    if(seniorList.get(promise.name) >= promise.value) {
                        seniorList.put(promise.name, seniorList.getOrDefault(promise.name, 0) - promise.value);
                        flag = true;
                        break;
                    }
                }

                if(flag) {
                    count++;
                } else {
                    ans = Math.max(ans, count);
                    count = 0;
                }
            }
        }
        stb.append(Math.max(ans, count));
        return stb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        seniorList = new HashMap<>();
        arr = new ArrayList[11][7];

        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 7; j++) {
                arr[i][j] = new ArrayList<>();
            }
        }

        String[] temp;

        for(int i = 0; i < N; i++) {
            temp = br.readLine().split(" ");
            String S = temp[0];
            int W = Integer.parseInt(temp[1]);
            int D = Integer.parseInt(temp[2]);
            int P = Integer.parseInt(temp[3]);

            arr[W][D].add(new Senior(S, P));
        }

        for(int i = 0; i < N; i++) {
            temp = br.readLine().split(" ");
            String S = temp[0];
            int P = Integer.parseInt(temp[1]);

            seniorList.put(S, P);
        }

        bw.write(solve());
        br.close();
        bw.close();
    }
}