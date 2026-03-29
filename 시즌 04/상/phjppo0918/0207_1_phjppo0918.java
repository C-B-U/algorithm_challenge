package org.example.dp.bj1949;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static List<Integer>[] tree;
    private static int[] people;
    private static int[] dpPick;
    private static int[] dpNoPick;
    public static void main(String [] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int size = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        people = new int[size + 1];
        dpPick = new int[size + 1];
        dpNoPick = new int[size + 1];
        tree = new List[size + 1];
        for (int i = 1; i <= size; i++) {
            people[i] = Integer.parseInt(st.nextToken());
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < size - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());
            tree[node1].add(node2);
            tree[node2].add(node1);
        }
        search(1, 0);
        sb.append(Math.max(dpNoPick[1], dpPick[1]));

        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }
    public static void search(int node, int parent) {
        for (int i : tree[node]) {
            if(i == parent) continue;
            search(i, node);
            dpNoPick[node] += Math.max(dpNoPick[i], dpPick[i]);
            dpPick[node] += dpNoPick[i];
        }
        dpPick[node] += people[node];
    }
}
