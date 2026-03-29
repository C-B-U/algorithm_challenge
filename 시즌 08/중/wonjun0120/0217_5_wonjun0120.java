import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Math;

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] rgbVal = new int[n][3];
        
        for(int i = 0; i < n; i++){
            String[] tmp = br.readLine().split(" ");
            rgbVal[i][0] = Integer.parseInt(tmp[0]);
            rgbVal[i][1] = Integer.parseInt(tmp[1]);
            rgbVal[i][2] = Integer.parseInt(tmp[2]);
        }

        for(int i = 1; i < n; i++){
            rgbVal[i][0] += Math.min(rgbVal[i - 1][1], rgbVal[i - 1][2]);
            rgbVal[i][1] += Math.min(rgbVal[i - 1][0], rgbVal[i - 1][2]);
            rgbVal[i][2] += Math.min(rgbVal[i - 1][0], rgbVal[i - 1][1]);
        }
        int minNum = Math.min(Math.min(rgbVal[n - 1][0], rgbVal[n - 1][1]), rgbVal[n - 1][2]);
        System.out.println(minNum);
    }
}
