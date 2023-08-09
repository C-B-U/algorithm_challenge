
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long num=Long.parseLong(br.readLine());

        long[] lengths = new long[(int) num];
        for (int i=0;i<num;i++){
            lengths[i]= Long.parseLong(br.readLine());
        }

        long max=-1;


        Arrays.sort(lengths);

        for (int i = 0; i < num-2; i++) {
            long a = lengths[i];
            long b = lengths[i +1];
            long c = lengths[i +2];



           if (a + b > c ) {
                   max = Math.max(max, a + b + c);
           }
           }
        System.out.println(max);

       }

        }



