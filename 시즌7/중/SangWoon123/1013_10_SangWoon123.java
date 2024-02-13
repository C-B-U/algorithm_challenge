
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static class Node implements Comparator<Node>{
        int start;
        int end;

        public Node(int start, int end) {
            this.start = start;
            this.end = end;
        }


        @Override
        public int compare(Node o1, Node o2) {
            if(o1.start==o2.start) return Integer.compare(o1.end,o2.end);
            return Integer.compare(o1.start,o2.start);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<Node> arr=new ArrayList<>();
        for(int i=0;i<n;i++){
            StringTokenizer st=new StringTokenizer(br.readLine());
            Node node=new Node(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            arr.add(node);
        }

        Collections.sort(arr, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(o1.start==o2.start) return Integer.compare(o1.end,o2.end);
                else return Integer.compare(o1.start,o2.start);
            }
        });

        PriorityQueue<Node> q=new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return Integer.compare(o1.end, o2.end);
            }
        });
        q.add(arr.get(0));

        for(int i=1;i<n;i++){

            if(q.peek().end <= arr.get(i).start) q.poll();

            q.add(arr.get(i));
        }

        System.out.println(q.size());

    }
}
