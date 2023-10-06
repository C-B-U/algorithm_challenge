import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());


        char[][] figure = new char[h][w];

        // 도형 입력 받기
        for (int i = 0; i < h; i++) {
            String line = br.readLine();
            for (int j = 0; j < w; j++) {
                figure[i][j] = line.charAt(j);
            }
        }

        double area = 0;

//        / or \로 감싸진 .은 1이고 밖에 나와 있는 .은 0 이다
//        / or \가 홀수가 있다면 안에 있는거고 짝수개 있다면 밖에 있는 것이다
//        So / or \의 개수가 홀수개일때 .이 나오면 +1, 짝수개일때 .이 나오면 더하지X
        for (int i = 0; i < h; i++) {
            int cnt = 0;
            for (int j = 0; j < w; j++) {
                if (figure[i][j] == '/' || figure[i][j] == '\\') {
                    cnt++;
                    area += 0.5;
                }
                if (figure[i][j] == '.') {
                    if (cnt%2==1) {
                        area += 1;
                    }
                    else continue;
                }
            }
        }

        System.out.println((int)area);

    }
}