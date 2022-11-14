import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Day01_중 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String> nList = new ArrayList<>();
        List<String> nmList = new ArrayList<>();


        String[] inputs = br.readLine().split(" ");
        int N,M;
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            nList.add(str);
        }

        for (int i = 0; i < M; i++) {
            String str = br.readLine();
            if (nList.contains(str)) {
                nmList.add(str);
            }
        }
        Collections.sort(nmList);

        System.out.println(nmList.size());
        for (String str : nmList) {
            System.out.println(str);
        }
    }
}
