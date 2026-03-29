
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

      int T=Integer.parseInt(br.readLine());

      for(int i=0;i<T;i++){
          StringTokenizer st=new StringTokenizer(br.readLine());
          int x1=Integer.parseInt(st.nextToken());
          int y1=Integer.parseInt(st.nextToken());
          int r1=Integer.parseInt(st.nextToken());

          int x2=Integer.parseInt(st.nextToken());
          int y2=Integer.parseInt(st.nextToken());
          int r2=Integer.parseInt(st.nextToken());

          System.out.println(terlet(x1,x2,y1,y2,r1,r2));
      }


    }

    private static int terlet(int x1, int x2, int y1, int y2, int r1, int r2) {
        int distance=(int) (Math.pow(x2-x1,2)+Math.pow(y2-y1,2));

        if(x1==x2 && y1==y2 && r1==r2) return -1;

        if(distance>Math.pow(r1+r2,2)) return 0;

        if(distance<Math.pow(r1-r2,2)) return 0;

        if(distance==Math.pow(r1-r2,2)) return 1;

        if(distance==Math.pow(r1+r2,2)) return 1;

        else return 2;
    }
}
