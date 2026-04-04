import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // M: 피해야 할 캐릭터 수
        // N: 속성의 개수
        // Q: 질문 가능 횟수
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] maxValues = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            maxValues[i] = Integer.parseInt(st.nextToken());
        }

        int[] myCharacter = new int[N + 1];

        for (int i = 1; i <= M; i++) {
            System.out.println("? " + i + " " + i);
            System.out.flush(); 

            String line = br.readLine();
            if (line == null) return; 
            int response = Integer.parseInt(line);

            if (response == 1) {
                myCharacter[i] = 2;
            } else {
                myCharacter[i] = 1;
            }
        }

        for (int i = M + 1; i <= N; i++) {
            myCharacter[i] = 1;
        }

        StringBuilder sb = new StringBuilder();
        sb.append("! ");
        for (int i = 1; i <= N; i++) {
            sb.append(myCharacter[i]).append(" ");
        }
        
        System.out.println(sb.toString());
        System.out.flush();
    }
}
