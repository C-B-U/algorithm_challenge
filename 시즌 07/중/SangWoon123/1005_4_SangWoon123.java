import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n=Integer.parseInt(br.readLine());

        int[][] arr=new int[n+1][n+1];

        // 노드리스트 생성
        ArrayList<Node> nodes=new ArrayList<>();

        for(int i=1;i<n+1;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=1;j<n+1;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                // 그래프에서 1의값을 가진 x,y값을 노드에 삽입
                if(arr[i][j]==1) nodes.add(new Node(i,j));
            }
        }

        // 2중 for문 돌면서 처음 꺼낸 노드의 y값과 다음 노드의 x값이 겹치면 새로운 노드 생성하여 리스트 삽입
        for (int i = 0; i < nodes.size() - 1; i++) {
            Node node = nodes.get(i);
            int firstX = node.x;
            int firstY = node.y;

            for (int j = 0; j < nodes.size(); j++) {
                Node nextNode = nodes.get(j);
                int checkX = nextNode.x;
                int checkY = nextNode.y;

                //  방문여부 체크 확인
                if (firstY == checkX && arr[firstX][checkY] != 1) {
                    nodes.add(new Node(firstX, checkY));
                    arr[firstX][checkY] = 1;
                }
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
}



}
