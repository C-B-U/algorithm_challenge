package Main;
import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		Problem P = new Problem();
		P.solve();
	}
}
class Problem {
	int[] parent;
	public Problem() {}
	public void solve() throws IOException {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        
        ArrayList<Integer> crane = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            crane.add(input.nextInt());
        }
        Collections.sort(crane, Collections.reverseOrder());
        
        int m = input.nextInt();
        ArrayList<Integer> box = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            box.add(input.nextInt());
        }
        Collections.sort(box, Collections.reverseOrder());
        
        if(crane.get(0) < box.get(0)) System.out.println("-1");
        else {
            int time = 0;
            while(!box.isEmpty()) {
                int index = 0;
                for(int i = 0; i < crane.size();) {
                    if(index == box.size()) break;
                    else if(crane.get(i) >= box.get(index)) {
                        box.remove(index);
                        i++;
                    }
                    else index++;
                }
                time++;
            }
            System.out.println(time);
        }
	}
}