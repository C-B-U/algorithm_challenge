import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashMap<Double,Integer> map = new HashMap<>();
        HashMap<Integer,Integer> map2 = new HashMap<>();
        ArrayList<Double> list = new ArrayList<>();
        int n = in.nextInt();
        for(int i=0;i<n;i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            double v = in.nextInt();
            double distance = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
            double time = distance / v;
            if (map.containsKey(time)) {
                map2.put(map.get(time), i + 1);
                continue;
            }
            map.put(time, i + 1);
            list.add(time);
        }
        Collections.sort(list);
        for(int i=0;i<list.size();i++){
            System.out.println(map.get(list.get(i)));
            if(map2.containsKey(map.get(list.get(i)))){
                System.out.println(map2.get(map.get(list.get(i))));
            }
        }
    }
}