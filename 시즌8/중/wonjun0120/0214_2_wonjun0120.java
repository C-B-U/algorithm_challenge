import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputVals = br.readLine().split(" ");

        String a = inputVals[0]; String b = inputVals[1];

        int minDiff = b.length();
        for(int i = 0; i < b.length() - a.length() + 1; i++){
            int diff = 0;
            for(int j = 0; j < a.length(); j++){
                if(a.charAt(j) == b.charAt(j + i));
                else diff += 1;
            }

            if(diff == 0){
                System.out.println(diff);
                return;
            }
            if(diff < minDiff) minDiff = diff;
        }
        System.out.println(minDiff);
    }
}