import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    private static int sum = 0;

    public static void main(String[] args) {
        Arrays.stream(inputs(" ")).map(Integer::parseInt).map(i -> i * i).forEach(i -> sum += i);
        System.out.println(sum % 10);
    }

    public static String[] inputs(String regex) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            return br.readLine().split(regex);
        } catch (IOException e) {
        }
        return null;
    }
    public static String input() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            return br.readLine();
        } catch (IOException e) {
        }
        return null;
    }
}

