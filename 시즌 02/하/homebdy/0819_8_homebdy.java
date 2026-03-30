import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class homebdy_7 {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine()," ");
        int n = Integer.parseInt(stringTokenizer.nextToken());
        int m = Integer.parseInt(stringTokenizer.nextToken());
        int lastLeaf = 0;

        for (int i = 1; i < n-m+1; i++) {
            System.out.println((i-1) + " " + i);
            lastLeaf = i;
        }
        for (int i = n-m+1; i < n; i++) {
            System.out.println(lastLeaf + " " + i);
        }
    }
}