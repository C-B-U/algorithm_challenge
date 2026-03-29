
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<Rank> rank=new ArrayList<>();

        int num=Integer.parseInt(br.readLine());

        for(int i=0;i<num;i++){
            String[] input=br.readLine().split(" ");
            double x=Double.parseDouble(input[0]);
            double y=Double.parseDouble(input[1]);

            double speed=Double.parseDouble(input[2]);

            double distance=Math.sqrt(x*x+y*y);

            double time=distance/speed;

            rank.add(new Rank(i+1,time));
        }

        Collections.sort(rank);

        for (Rank result: rank){
            System.out.println(result.num);
        }


    }



}

class Rank implements Comparable<Rank>{
    int num;
    double time;

    public Rank(int num, double time) {
        this.num = num;
        this.time = time;
    }

    @Override
    public int compareTo(Rank o) {
        return Double.compare(this.time,o.time);
    }
}