import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //개미그룹의 수 n1, n2 입력
        int n1 = Integer.parseInt(st.nextToken());
        int n2 = Integer.parseInt(st.nextToken());
        int t, temp;
        int i = 0, j = 0;

        //개미 입력
        String[] ant = new String[2];
        while(i < 2) {
            ant[i] = br.readLine();
            i++;
        }
        t = Integer.parseInt(br.readLine());

        //첫번째 개미 그룹(ant[0]) 문자열을 reverse
        StringBuilder sb0 = new StringBuilder(ant[0]);
        ant[0] = sb0.reverse().toString();
        StringBuilder ans = new StringBuilder();

        //t가 n1 + n2 - 1 이상인 경우 개미의 순서는 똑같기 때문에 t = n1 + n2 - 1
        if (t > n1 + n2) {
            t = n1 + n2 - 1;
        }

        i = 0; j = 0;
        if (n1 >= t) {
            temp = n1 - t;

            //n1 - t 만큼 ant[0]의 문자를 추가
            for (i = 0; i < temp; i++)
                ans.append(ant[0].charAt(i));

            //ant[1]과 ant[0]의 문자를 순서대로 추가
            int min = Math.min(n1 - i, n2);
            min = Math.min(min, t);
            for (temp = 0; temp < min; temp++) {
                ans.append(ant[1].charAt(j));
                ans.append(ant[0].charAt(i));
                j++; i++;
            }

            //남은 문자가 있으면 추가
            if (j < n2) {
                for ( ; j < n2; j++)
                    ans.append(ant[1].charAt(j));
            }
            if (i < n1) {
                for ( ; i < n1; i++)
                    ans.append(ant[0].charAt(i));
            }
        }
        else {
            temp = t - n1;

            //t - n1 + 1 만큼 ant[1]의 문자를 추가
            for (j = 0; j <= temp; j++)
                ans.append(ant[1].charAt(j));

            //ant[0]과 ant[1]의 문자를 슨서대로 추가
            int min = Math.min(n1, n2 - j);
            min = Math.min(min, t);
            for (temp = 0; temp < min; temp++) {
                ans.append(ant[0].charAt(i));
                ans.append(ant[1].charAt(j));
                i++; j++;
            }

            //남은 문자가 있으면 추가
            if (i < n1) {
                for ( ; i < n1; i++)
                    ans.append(ant[0].charAt(i));
            }
            if (j < n2) {
                for ( ; j < n2; j++)
                    ans.append(ant[1].charAt(j));
            }
        }
        System.out.println(ans);
    }
}
