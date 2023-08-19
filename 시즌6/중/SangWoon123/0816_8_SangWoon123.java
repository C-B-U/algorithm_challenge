
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N=Integer.parseInt(br.readLine());

        String[] size=br.readLine().split(" ");
        int sizeX = Integer.parseInt(size[0]);
        int sizeY = Integer.parseInt(size[1]);

        Map<Integer,List<Integer>> point=new HashMap<>();

        for(int i=0;i<N;i++){
            String[] input=br.readLine().split(" ");
            int x=Integer.parseInt(input[0]);
            int y=Integer.parseInt(input[1]);

            List<Integer> yList=point.getOrDefault(x,new ArrayList<>());
            yList.add(y);
            point.put(x,yList);
        }

        int count=0;
        for (int x: point.keySet()){
            if(point.containsKey(x+sizeX)){
                List<Integer> yList=point.get(x);
                List<Integer> compareY=point.get(x+sizeX);
                for (int y: yList){
                    if(compareY.contains(y)&&compareY.contains(y+sizeY)&&yList.contains(y+sizeY)){
                        count++;
                    }
                }
            }
        }

        System.out.println(count);



    }}