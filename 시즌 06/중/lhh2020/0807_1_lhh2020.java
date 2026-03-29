import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static int sum = 0;

    public static void main(String[] args) {
        String[] inputs = inputs(" ");

        long x = Long.parseLong(inputs[0]);
        long y = Long.parseLong(inputs[1]);
        long c1 = Long.parseLong(inputs[2]);
        long c2 = Long.parseLong(inputs[3]);

        long x_c = 0, y_c = 0;
        long cost = 0;

        if (c1*2 < c2) {
            System.out.println((x + y)*c1);
            return;
        }

        x_c = Math.min(x, y);
        y_c = x_c;
        cost += x_c*c2;

        long leftSteps = x - x_c + y - y_c;


        if (c1 > c2) {
            if (leftSteps % 2 == 0) {
                cost += leftSteps*c2;
            } else {
                cost += (leftSteps - 1)*c2 + c1;
            }
            System.out.println(cost);
            return;
        }
        // else
        cost += leftSteps*c1;
        System.out.println(cost);
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

