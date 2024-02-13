package 경로찾기_11403번;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st ;

        int n = Integer.parseInt(br.readLine());

//        인접 행렬을 위한 이차원 배열
        int[][] graph = new int[n][n];

        // 인접 행렬 그래프 배열 입력 받기
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }
//        k : 거쳐가는 노드
        for (int k = 0; k < n; k++) {
//            i : 출발 노드
            for (int i = 0; i < n; i++) {
//                j : 도착 노드
                for (int j = 0; j < n; j++) {
//                    직접 가는 경로가 없는 경우(0인 경우) -> 거쳐 가는 노드(k)를 통해 가는 경로가 있는지 확인
                    if (graph[i][j] == 0) {
                        if (graph[i][k] != 0 && graph[k][j] != 0) { // k 노드를 거쳐 가는 경로가 있다면 0을 1로 변경
                            graph[i][j] = 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bw.write(Integer.toString(graph[i][j]));
                bw.write(" ");
            }
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }
}
