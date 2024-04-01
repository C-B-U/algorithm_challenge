import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<Integer> crane = new ArrayList<>();
        String[] temp = br.readLine().split(" ");

        for(int i = 0; i < N; i++) {
            crane.add(Integer.parseInt(temp[i]));
        }

        int M = Integer.parseInt(br.readLine());
        List<Integer> box = new ArrayList<>();
        temp = br.readLine().split(" ");

        for(int i = 0; i < M; i++) {
            box.add(Integer.parseInt(temp[i]));
        }

        crane.sort(Collections.reverseOrder());
        box.sort(Collections.reverseOrder());

        if(crane.get(0) < box.get(0)) {
            System.out.println(-1);
            return;
        }
        
        int count = 0;
        while(!box.isEmpty()) {
            int boxIndex = 0, craneIndex = 0;

            while(craneIndex < N) {
                if(boxIndex == box.size()) {
                    break;
                } else if(crane.get(craneIndex) >= box.get(boxIndex)) {
                    box.remove(boxIndex);
                    craneIndex++;
                } else {
                    boxIndex++;
                }
            }

            count++;
        }

        System.out.println(count);
    }
}