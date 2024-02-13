
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static class P {
        int x;
        int y;

        public P(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<P> dots = new ArrayList<>();

        for(int i=0;i<3;i++){
            StringTokenizer st=new StringTokenizer(br.readLine());
            P p=new P(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            dots.add(p);
        }

        int answer=check(dots);

        System.out.println(answer);


    }

    private static int check(ArrayList<P> dots) {

        P p1=dots.get(0);
        P p2=dots.get(1);
        P p3=dots.get(2);

        int crossProduct = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);

        if(crossProduct > 0)
            return 1;

        else if(crossProduct < 0)
            return -1;

        else
            return 0;
    }
}
