
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Day4 {
    public static void main(String[] args) throws IOException{
        // x << y 는 x를 y만큼 왼쪽으로 시프트하는 연산
        // 8 << 2는 8을 2만큼 왼쪽으로 시프트하여 32가 된다.
        // 1 << k는 2^k를 의미하며, 이는 k자리 이하의 자연수의 개수를 나타낸다.
        // 예를 들어, k=3일 때, 1 << 3은 8이므로 1부터 7까지의 자연수를 포함한다.
        // 이렇게 계산으로 풀려했으나, 입력해야 하는 수가 너무나도 크기에 반드시 시간초과가 나고, 이런 경우는 규칙성을 찾으면 해결이 쉽다.
        // 수의 범위가 10만자리도 해당하므로 int형으로 표기하기엔 메모리 에러가 심하다.
        // 결국, 계산을 하는 문제가 아니라 문자열로 규칙을 찾는 문제였다.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            sb.append("1");
        }

        for (int i = 0; i < n - 1; i++) {
            sb.append("0");
        }
        bw.write(sb.toString());
        bw.close();
    }
}
