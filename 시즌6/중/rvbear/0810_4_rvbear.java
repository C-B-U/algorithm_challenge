import java.io.*;

public class Main {
    public static int check_index(char c) {                 // 알파벳 사용 여부를 파악할 인덱스 구하는 함수
        return Character.toUpperCase(c) - 65;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());            // 입력할 라인의 개수
        boolean flag = false;                               // 구분자로 사용
        boolean[] visit = new boolean[26];                  // 알파벳 사용 여부를 저장할 배열

        for(int i = 0; i < n; i++) {
            String line = br.readLine();
            if(line.contains(" ")) {                        // 여러 단어로 이루어진 문자열일 경우
                String[] s = line.split(" ");               // 단어들을 s 배열에 저장
                for(int j = 0; j < s.length; j++) {
                    if(!visit[check_index(s[j].charAt(0))]) {       // 단어의 첫번째 글자만 검사
                        visit[check_index(s[j].charAt(0))] = true;
                        for(int k = 0; k < j; k++) {
                            bw.write(s[k] + " ");
                        }
                        bw.write("["+s[j].charAt(0)+"]"+s[j].substring(1)+" ");
                        for(int k = j+1; k < s.length; k++) {
                            bw.write(s[k] + " ");
                        }
                        bw.write("\n");
                        flag = true;
                        break;
                    }
                }
                if(!flag) {                                  // 단어의 첫번째 글자가 모두 단축키로 지정되있으면
                    for(int j = 1; j < line.length(); j++) { // 두번째 글자부터 확인
                        if(line.charAt(j) != ' ' && !visit[check_index(line.charAt(j))]) {
                            visit[check_index(line.charAt(j))] = true;
                            bw.write(line.substring(0, j)+"["+line.charAt(j)+"]"+line.substring(j+1)+"\n");
                            flag = true;
                            break;
                        }
                    }
                }
            } else {                                          // 하나의 단어로 이루어진 문자열일 경우
                for(int j = 0; j < line.length(); j++) {
                    if(!visit[check_index(line.charAt(j))]) { // 처음부터 탐색 시작
                        visit[check_index(line.charAt(j))] = true;
                        bw.write(line.substring(0, j)+"["+line.charAt(j)+"]"+line.substring(j+1)+"\n");
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag) {                                       // 탐색을 했는데 모두 사용 중일 경우
                bw.write(line+"\n");
            }
            flag = false;                                     // 구분자 초기화
        }

        br.close(); bw.close();
    }
}