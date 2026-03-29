package org.example.bruteforce.bj15898;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static int[][][][] effect;
    private static char[][][][] color;
    private static boolean[] visited;
    private static int answer = 0;
    private static int caseSize;

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        caseSize = Integer.parseInt(st.nextToken());
        visited = new boolean[caseSize];
        Element[][] graph = new Element[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                graph[i][j] = new Element(0, 'W');
            }
        }
        effect = new int[caseSize][4][4][4];
        color = new char[caseSize][4][4][4];
        for (int i = 0; i < caseSize; i++) {
            for (int j = 0; j < 4; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < 4; k++) {
                    effect[i][0][j][k] = Integer.parseInt(st.nextToken());
                }
            }
            for (int j = 0; j < 4; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < 4; k++) {
                    color[i][0][j][k] = st.nextToken().charAt(0);
                }
            }

            for (int j = 1; j < 4; j++) {
                turn(i, j);
            }
        }
        dfs(graph, 0);

        sb.append(answer);

        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }

    private static void dfs(Element[][] graph, int cnt) {
        if (cnt == 3) {
            answer = Math.max(answer, getValue(graph));
            return;
        }

        for (int t = 0; t < caseSize; t++) {
            if (!visited[t]) {
                visited[t] = true;

                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        for (int d = 0; d < 4; d++) {
                            Element[][] tmp = mix(graph, i, j, t, d);

                            dfs(tmp, cnt + 1);
                        }
                    }
                }

                visited[t] = false;
            }
        }
    }

    private static int getValue(Element[][] graph) {
        int r = 0;
        int b = 0;
        int g = 0;
        int y = 0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                switch (graph[i][j].color) {
                    case 'R':
                        r += graph[i][j].effect;
                        break;
                    case 'B':
                        b += graph[i][j].effect;
                        break;
                    case 'G':
                        g += graph[i][j].effect;
                        break;
                    case 'Y':
                        y += graph[i][j].effect;
                        break;
                    default:
                        break;
                }
            }
        }
        return 7 * r + 5 * b + 3 * g + 2 * y;
    }
    private static Element[][] mix(Element[][] graph, int row, int col, int type, int dir) {
        Element[][] result = new Element[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                result[i][j] = new Element(graph[i][j].effect, graph[i][j].color);
            }
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                // 효능
                result[row+i][col+j].effect += effect[type][dir][i][j];

                if(result[row+i][col+j].effect < 0)
                    result[row+i][col+j].effect = 0;
                else if(result[row+i][col+j].effect > 9)
                    result[row+i][col+j].effect = 9;

                // 원소
                if(color[type][dir][i][j] != 'W'){
                    result[row+i][col+j].color = color[type][dir][i][j];
                }
            }
        }

        return result;
    }

    private static void turn(int index, int dir) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                effect[index][dir][i][j] = effect[index][dir - 1][3 - j][i];
                color[index][dir][i][j] = color[index][dir - 1][3 - j][i];
            }
        }
    }
}

class Element {
    int effect;
    char color;

    public Element(int effect, char color) {
        this.effect = effect;
        this.color = color;
    }
}
