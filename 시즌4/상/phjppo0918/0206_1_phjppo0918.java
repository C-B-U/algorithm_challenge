package org.example.dp.bj12969;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static char[] answer;
    private static boolean[][][][] visited;
    private static int size;
    private static int pc;
    private static String answerStr = "";

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        size = Integer.parseInt(st.nextToken());
        pc = Integer.parseInt(st.nextToken());
        answer = new char[size];
        visited = new boolean[32][32][32][440];

        ;
        if (dp(1, 0, 0, 0)) {
            sb.append(answerStr);
        } else {
            sb.append(-1);
        }

        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }

    private static boolean dp(int level, int aCount, int bCount, int pairCount) {
        if (pairCount > pc) {
            return false;
        }
        if(visited[level][aCount][bCount][pairCount]) {
            return false;
        }
        visited[level][aCount][bCount][pairCount] = true;
        if (level > size) {
            if (pairCount == pc) {
                StringBuilder sb = new StringBuilder();
                for (char c : answer) {
                    sb.append(c);
                }
                answerStr = sb.toString();
                return true;
            }
            return false;
        }

        answer[level - 1] = 'A';
        if(dp(level + 1, aCount + 1, bCount, pairCount)) {
            return true;
        }
        answer[level - 1] = 'B';
        if(dp(level + 1, aCount, bCount + 1, pairCount + aCount)) {
            return true;
        }
        answer[level - 1] = 'C';
        if(dp(level + 1, aCount, bCount, pairCount + aCount + bCount)) {
            return true;
        }
        return false;
    }
}

