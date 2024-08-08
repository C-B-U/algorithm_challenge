import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        int[] stack = new int[N];
        int index = 0;

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            switch (st.nextToken()) {
                case "push":
                    stack[index++] = Integer.parseInt(st.nextToken());
                    break;
                case "pop":
                    bw.write((index == 0 ? -1 : stack[--index]) + "\n");
                    break;
                case "size":
                    bw.write(index + "\n");
                    break;
                case "empty":
                    bw.write((index == 0 ? 1 : 0) + "\n");
                    break;
                case "top":
                    bw.write((index == 0 ? -1 : stack[index-1]) + "\n");
                    break;
            }
        }

        bw.close();
    }
}