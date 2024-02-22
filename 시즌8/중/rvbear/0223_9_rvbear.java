import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    static int result = 0;
    static ArrayList<Integer>[] tree;
    static boolean[] visit;

    public static void deleteNode(int index) {
        visit[index] = true;
        for(int value : tree[index]) {
            if(!visit[value]) {
                deleteNode(value);
            }
        }
    }
    public static void dfs(int index) {
        int count = 0;
        if(visit[index]) {
            return;
        }

        for(int value : tree[index]) {
            if(!visit[value]) {
                dfs(value);
                count++;
            }
        }

        if(!visit[index] && count == 0) {
            result++;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] temp = br.readLine().split(" ");
        tree = new ArrayList[N];
        visit = new boolean[N];

        for(int i = 0; i < N; i++) {
            tree[i] = new ArrayList<>();
        }

        int root = 0;

        for(int i = 0; i < N; i++) {
            int value = Integer.parseInt(temp[i]);
            if(value == -1) {
                root = i;
            } else {
                tree[value].add(i);
            }
        }

        int remove = Integer.parseInt(br.readLine());

        deleteNode(remove);
        dfs(root);
        System.out.println(result);
    }
}