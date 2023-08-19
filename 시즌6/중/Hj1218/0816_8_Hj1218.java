import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair implements Comparable<Pair> {
    long x;
    long y;
    public Pair(long x, long y){
        this.x=x;
        this.y=y;
    }
    public long getX(){
        return x;
    }
    public long getY(){
        return y;
    }
    @Override
    public int compareTo(Pair o){
        if(x==o.x){
            return Long.compare(y, o.y);
        }
        return Long.compare(x,o.x);
    }
}
public class Main {
    static List<Pair> list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String ss = br.readLine();
        StringTokenizer st = new StringTokenizer(ss," ");
        int a = Integer.parseInt(st.nextToken()); //가로
        int b = Integer.parseInt(st.nextToken()); //세로
        list = new ArrayList<>();
        long []x = new long[n];
        long []y = new long[n];
        for(int i=0;i<n;i++){
            String s = br.readLine();
            st = new StringTokenizer(s," ");
            x[i]= Long.parseLong(st.nextToken());
            y[i]= Long.parseLong(st.nextToken());
            list.add(new Pair(x[i],y[i]));
        }
        Collections.sort(list);
        long count=0;
        for(int i=0;i<n;i++){
            if(check(x[i]+a,y[i])&&check(x[i],y[i]+b)&&check(x[i]+a,y[i]+b)){
                count++;
            }
        }
        System.out.println(count);
    }
    static boolean check(long xx, long yy){
        int start = 0;
        int end = list.size()-1;
        int mid;
        while(start<=end){
            mid = (start+end)/2;
            if(list.get(mid).getX()==xx&&list.get(mid).getY()==yy){
                return true;
            }
            if(list.get(mid).getX()>xx){
                end = mid-1;
            }
            else if(list.get(mid).getX()<xx){
                start = mid+1;
            }
            else{
                if(list.get(mid).getY()>yy){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        return false;
    }
}