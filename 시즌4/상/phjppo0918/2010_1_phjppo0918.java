package org.example.graph.bj1113;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    static int[][] graph;
    static boolean[][] isProgressVisit;
    static boolean[][] isOver;
    static int row;
    static int col;
    static int[] rowPivot = {-1, 1, 0, 0};
    static int[] colPivot = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());
        graph = new int[row][];
        isProgressVisit = new boolean[row][col];
        isOver = new boolean[row][col];
        for (int i = 0; i < row; i++) {
            graph[i] = br.readLine().chars().map(c -> c - '0').toArray();
        }
        int answer = 0;

        for (int height = 2; height <= 9; height++) {
            isProgressVisit = new boolean[row][col];
            for (int i = 1; i < row-1; i++) {
                for (int j = 1; j < col-1; j++) {
                    if (!isProgressVisit[i][j] && graph[i][j] < height && !isOver[i][j]) {
                        boolean isOut = false;
                        Set<Node> visited = new HashSet<>();
                        Queue<Node> nodes = new LinkedList<>();
                        isProgressVisit[i][j] = true;
                        visited.add(new Node(i, j));
                        nodes.add(new Node(i, j));
                        while (!nodes.isEmpty()) {
                            Node now = nodes.poll();
                            for (int k = 0; k < 4; k++) {
                                int nextRow = now.row + rowPivot[k];
                                int nextCol = now.col + colPivot[k];
                                if(isOutOfRange(nextRow, nextCol)) {
                                    continue;
                                }

                                if((isEdge(nextRow, nextCol) && graph[nextRow][nextCol] < height) || isOver[nextRow][nextCol]) {
                                    isOut = true;
                                    continue;
                                }

                                if(!isEdge(nextRow, nextCol)&& !isProgressVisit[nextRow][nextCol] && graph[nextRow][nextCol] < height) {
                                    nodes.add(new Node(nextRow, nextCol));
                                    visited.add(new Node(nextRow, nextCol));
                                    isProgressVisit[nextRow][nextCol] = true;
                                }
                            }
                        }

                        if(isOut) {
                            visited.stream().forEach(n -> isOver[n.row][n.col] = true);
                        }else {
                            answer+= visited.size();
                        }
                    }
                }
            }
        }
        sb.append(answer);

        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }

    private static boolean isEdge(int x, int y) {
        if (x == 0 || y == 0 || x == row - 1 || y == col - 1) {
            return true;
        }
        return false;
    }

    private static boolean isOutOfRange(int x, int y) {
        if (x < 0 || y < 0 || x >= row  || y >= col) {
            return true;
        }
        return false;
    }

}

class Node {
    int row;
    int col;

    public Node(int row, int col) {
        this.row = row;
        this.col = col;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Node node = (Node) o;
        return row == node.row && col == node.col;
    }

    @Override
    public int hashCode() {
        return Objects.hash(row, col);
    }
}
