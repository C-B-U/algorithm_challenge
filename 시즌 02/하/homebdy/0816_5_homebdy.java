import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Stack {

    private int[] stack;
    private int top;

    public Stack(int size) {
        this.stack = new int[size];
        this.top = -1;
    }

    public void push(int num) {
        stack[++top] = num;
    }

    public int pop() {
        if (top == -1)
            return -1;
        int num = stack[top];
        stack[top] = 0;
        top--;
        return num;
    }

    public int size() {
        return top + 1;
    }

    public int empty() {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    public int top() {
        if (top == -1)
            return -1;
        return stack[top];
    }

}

class homebdy_5 {

    static Stack stack;

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(bufferedReader.readLine());

        stack = new Stack(num);

        for (int i = 0; i < num; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
            String command = stringTokenizer.nextToken();
            if (stringTokenizer.hasMoreTokens()) {
                int commandNum = Integer.parseInt(stringTokenizer.nextToken());
                saveStack(command, commandNum);
            }
            else {
                saveStack(command);
            }
        }
    }

    static void saveStack(String command, int commandNum) {
        if (command.equals("push")) {
            stack.push(commandNum);
        }
    }

    static void saveStack(String command) {
        int res;

        switch (command) {
            case "pop":
                res = stack.pop();
                break;
            case "size":
                res = stack.size();
                break;
            case "top":
                res = stack.top();
                break;
            case "empty":
                res = stack.empty();
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + command);
        }
        System.out.println(res);
    }
}