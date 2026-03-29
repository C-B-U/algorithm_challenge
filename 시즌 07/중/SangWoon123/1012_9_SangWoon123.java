
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] check=new int[100001];
    static int n,k;

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        n=Integer.parseInt(st.nextToken());
        k=Integer.parseInt(st.nextToken());

        if(n==k) {
            System.out.println(0);
        } else bfs(n);

    }

    private static void bfs(int num) {
        Queue<Integer> q=new LinkedList<>();
        q.add(num);
        check[num]=1;

        while (!q.isEmpty()){
            int now=q.poll();

            for(int i=0;i<3;i++){
                int nx;
                if(i==0) nx=now-1;
                else if(i==1) nx=now+1;
                else nx=now*2;

                if(nx==k) {
                    System.out.println(check[now]);
                    return;
                }

                if(nx>=0 && nx<100001 && check[nx]==0){
                    q.add(nx);
                    check[nx]=check[now]+1;
                }

            }
        }
    }


}
