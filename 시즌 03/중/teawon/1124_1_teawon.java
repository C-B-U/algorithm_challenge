import java.util.*;
import java.io.*;

/*
 * 문제 주소 :  https://www.acmicpc.net/problem/4949
 *  | 256ms
 * 
*/

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Stack<Character> stack = new Stack<>();
        while (true) {
            String str = br.readLine();
            stack.clear();
            if (str.equals(".")) {
                break;
            }
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) == '(' || str.charAt(i) == '[') {
                    stack.push(str.charAt(i));
                }

                else if (str.charAt(i) == ')' || str.charAt(i) == ']') {
                    if (str.charAt(i) == ')') {
                        if (stack.isEmpty() || stack.pop() != '(') {
                            sb.append("no\n");
                            break;
                        }
                    } else {
                        if (stack.isEmpty() || stack.pop() != '[') {
                            sb.append("no\n");
                            break;
                        }
                    }
                }
                if (i == str.length() - 1) {
                    if (stack.isEmpty() || stack.isEmpty()) {
                        sb.append("yes\n");
                    } else {
                        sb.append("no\n");
                    }

                }
            }
        }
        System.out.print(sb);
    }

}