
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int T,N,M,K;
    static int[] dirX={1,-1,0,0};
    static int[] dirY={0,0,1,-1};
    static int[][] map;
    static boolean[][] visit;
    static int count;
    static ArrayList<Integer> answer=new ArrayList<>();

    //dfs 완전탐색
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T=Integer.parseInt(br.readLine());

        for(int j=0;j<T;j++){
            st=new StringTokenizer(br.readLine());
            M=Integer.parseInt(st.nextToken());
            N=Integer.parseInt(st.nextToken());
            // 배추심어져있는 개수
            K=Integer.parseInt(st.nextToken());

            visit=new boolean[M][N];
            map=new int[M][N];


            for(int i=0;i<K;i++){
                st=new StringTokenizer(br.readLine());
                int x=Integer.parseInt(st.nextToken());
                int y=Integer.parseInt(st.nextToken());

                map[x][y]=1;
            }

            for(int i=0;i<M;i++){
                for(int k=0;k<N;k++){
                    if(!visit[i][k] && map[i][k]==1){
                        dfs(i,k);
                        count++;
                    }
                }
            }
            answer.add(count);
            count=0;

        }

        for (int i=0;i< answer.size();i++){
            System.out.println(answer.get(i));
        }



    }

    private static void dfs(int x, int y) {
        visit[x][y]=true;

        for(int i=0;i<4;i++){
            int nx=x+dirX[i];
            int ny=y+dirY[i];

            if(nx>=0 && nx<M && ny>=0 && ny<N &&!visit[nx][ny] && map[nx][ny]==1 ){
                visit[nx][ny]=true;
                dfs(nx,ny);
            }
        }

    }
}
