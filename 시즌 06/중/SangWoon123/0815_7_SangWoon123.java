
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

//4 2
//1 2 100 101

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        String[] first=br.readLine().split(" ");
        String[] second=br.readLine().split(" ");

        int N=Integer.parseInt(first[0]);
        int tape=Integer.parseInt(first[1]);

        List<Integer> list=new ArrayList<>();

        for (int i=0;i<second.length;i++){
            list.add(Integer.parseInt(second[i]));
        }

        Collections.sort(list);

        int count=1;

        int start=list.get(0);
        for (int i=1;i<list.size();i++){
            if(list.get(i) >=start && list.get(i)<start+tape){
                continue;
            }
            start=list.get(i);
            count+=1;
        }

        System.out.println(count);

    }
       }