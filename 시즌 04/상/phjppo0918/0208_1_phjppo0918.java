package org.example.graph.bj1198;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static final char wall = '#';
    private static final char out = '1';
    private static final char load = '.';
    private static char[][] graph;
    private static boolean[][][] visit;

    private static int row;
    private static int col;

    private static int[] rowMove = {-1, 1, 0, 0};
    private static int[] colMove = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());
        graph = new char[row][];
        visit = new boolean[64][row][col];
        int parsonRow = -1;
        int parsonCol = -1;
        for (int i = 0; i < row; i++) {
            graph[i] = br.readLine().toCharArray();
            for (int j = 0; j < col; j++) {
                if (graph[i][j] == '0') {
                    parsonRow = i;
                    parsonCol = j;
                }
            }
        }
        int answer = bfs(parsonRow, parsonCol);
        sb.append(answer);

        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }

    private static int bfs(int startRow, int startCol) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(startRow, startCol, 0,0));
        visit[0][startRow][startCol] = true;
        while (!queue.isEmpty()) {
            Node now = queue.poll();
            int row = now.row;
            int col = now.col;
            int count = now.count;
            int key = now.key;
            if(graph[row][col] == out) {
                return count;
            }
            for (int i = 0; i < 4; i++) {
                int nextRow = row + rowMove[i];
                int nextCol = col + colMove[i];
                if(!isOutRange(nextRow, nextCol) && graph[nextRow][nextCol] != wall && !visit[key][nextRow][nextCol]) {
                    char next = graph[nextRow][nextCol];
                    if(next == load || next == '0' || next == out) {
                        visit[key][nextRow][nextCol] = true;
                        queue.add(new Node(nextRow, nextCol, count + 1, key));
                    }else if(isKey(nextRow, nextCol)) {
                        int newKey = 1 << (next - 'a');
                        newKey |= key;
                        if(!visit[newKey][nextRow][nextCol]) {
                            visit[newKey][nextRow][nextCol] = true;
                            visit[key][nextRow][nextCol] = true;
                            queue.add(new Node(nextRow, nextCol, count + 1, newKey));
                        }
                    }else if(isDoor(nextRow, nextCol)) {
                        int door = 1 <<( next - 'A');
                        if((key & door) > 0)  {
                            visit[key][nextRow][nextCol] = true;
                            queue.add(new Node(nextRow, nextCol, count + 1, key));
                        }
                    }
                }
            }

        }

        return -1;
    }

    private static boolean isOutRange(int nowRow, int nowCol) {
        if (nowRow < 0 || nowRow >= row || nowCol < 0 || nowCol >= col) {
            return true;
        }
        return false;
    }

    private static boolean isKey(int nowRow, int nowCol) {
        return graph[nowRow][nowCol] >= 'a' && graph[nowRow][nowCol] <= 'f';
    }

    private static boolean isDoor(int nowRow, int nowCol) {
        return graph[nowRow][nowCol] >= 'A' && graph[nowRow][nowCol] <= 'F';
    }

    private static char toKey(char door) {
        return (char) (door + 32);
    }
}
class Node {
    int row;
    int col;
    int count;
    int key;

    public Node(int row, int col, int count, int key) {
        this.row = row;
        this.col = col;
        this.count = count;
        this.key = key;
    }
}
