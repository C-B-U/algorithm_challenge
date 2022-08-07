import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main{
	public static void main(String[] args) throws Exception {
	    
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
      
        int input = Integer.parseInt(st.nextToken());
        int passCount = 1;
        int roomLimit = 1;
        if(input!=1){
            while(input > roomLimit){
                roomLimit += 6*passCount++;
            }
        }
        bw.write(passCount + "\n");
           
        bw.flush();
        br.close();
        bw.close();
	}
}
