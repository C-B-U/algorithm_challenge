import java.io.*;

public class Main {
    static int[][] data;
    static StringBuilder stb = new StringBuilder();
    public static boolean isPossible(int x, int y, int size) {      // 압축할 수 있는지 여부 판단하는 메서드
        for(int i = x; i < x+size; i++) {
            for(int j = y; j < y+size; j++) {
                if(data[x][y] != data[i][j]) {                      // 압축할 수 없다면 return false
                    return false;
                }
            }
        }
        return true;                                                // 압축할 수 있다면 return true
    }
    public static void tree(int x, int y, int size) {               // 데이터를 탐색하는 메서드
        if(isPossible(x, y, size)) {                                // 압축가능 여부를 판단하여
            stb.append(data[x][y]);                                 // 압축이 가능하다면 압축한 값을 출력하고 return
            return;
        }

        int nSize = size/2;                                         // 불가능하다면 size를 반으로 줄여줌

        stb.append("(");                            // 값을 나눴다면 괄호를 열어줌
        tree(x, y, nSize);                          // 왼쪽 위
        tree(x, y + nSize, nSize);                  // 오른쪽 위
        tree(x + nSize, y, nSize);                  // 왼쪽 아래
        tree(x + nSize, y + nSize, nSize);          // 오른쪽 아래
        stb.append(")");                            // 해당 부분의 탐색이 끝나면 괄호를 닫아줌
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        data = new int[n][n];                       // 데이터의 정보를 저장할 배열
        for(int i = 0; i < n; i++) {
            String line = br.readLine();
            for(int j = 0; j < n; j++) {
                data[i][j] = line.charAt(j) - '0';  // 값을 저장
            }
        }

        tree(0, 0, n);                              // 탐색 메서드 호출

        System.out.println(stb);                    // 저장된 값을 출력
        br.close();
    }
}