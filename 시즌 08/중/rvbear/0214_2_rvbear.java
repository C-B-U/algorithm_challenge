import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int min = 51;

        String[] arr = br.readLine().split(" ");

        for(int i = 0; i <= arr[1].length() - arr[0].length(); i++) {
            String B = arr[1].substring(i);
            int temp = 0;
            for(int j = 0; j < arr[0].length(); j++) {
                if(B.charAt(j) != arr[0].charAt(j)) {
                    temp++;
                }
            }
            min = Math.min(temp, min);
        }

        System.out.println(min);
    }
}
