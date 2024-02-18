import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Math;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arrADiffB = new int[n];

        if(n % 2 == 1){
            System.out.println(1);
            return;
        }


        for(int i = 0; i < n; i++){
            String[] num_arr = br.readLine().split(" ");
            arrADiffB[i] = Integer.parseInt(num_arr[0]) - Integer.parseInt(num_arr[1]);
        }

        Arrays.sort(arrADiffB);

        int arrLen = arrADiffB.length;
        System.out.println(Math.abs(arrADiffB[arrLen / 2 - 1] - arrADiffB[arrLen / 2]) + 1);
    }
}