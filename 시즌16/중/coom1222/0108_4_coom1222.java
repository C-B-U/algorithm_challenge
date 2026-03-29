import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String S = br.readLine();
        String base = "toycartoon";
        
        // 1. O 찾기 (S의 접두사이면서 toycartoon의 부분문자열인 가장 긴 것)
        String O = "";
        int oIndexInBase = -1;
        
        // 길이가 긴 접두사부터 검사 (S 전체 ~ 1글자)
        for (int i = S.length(); i >= 1; i--) {
            String prefix = S.substring(0, i);
            int idx = base.indexOf(prefix);
            
            // indexOf는 가장 먼저 발견되는 인덱스를 반환하므로 
            // "가장 앞에 있는 문자열을 선택한다"는 조건 자동 만족
            if (idx != -1) {
                O = prefix;
                oIndexInBase = idx;
                break;
            }
        }
        
        String candidate = "";
        
        // 2. 조건에 따라 후보 이름 생성
        if (O.isEmpty()) {
            // O의 길이가 0인 경우
            candidate = base + "_" + S;
        } else {
            // O의 길이가 1 이상인 경우
            
            // T: O의 앞부분
            String T = base.substring(0, oIndexInBase);
            // Y: O의 뒷부분
            String Y = base.substring(oIndexInBase + O.length());
            
            // S_remain: S에서 O를 제외한 나머지 부분
            String S_remain = S.substring(O.length());
            
            // S_remain의 접미사이면서 Y의 접두사인 가장 긴 문자열 찾기
            int overlapLen = 0;
            int maxLen = Math.min(S_remain.length(), Y.length());
            
            for (int len = maxLen; len >= 1; len--) {
                String suffix = S_remain.substring(S_remain.length() - len);
                String prefix = Y.substring(0, len);
                
                if (suffix.equals(prefix)) {
                    overlapLen = len;
                    break; // 가장 긴 것을 찾았으므로 종료
                }
            }
            
            // Y의 앞에서 겹치는 부분 제거
            String Y_new = Y.substring(overlapLen);
            
            // 후보 조합: T + S + Y_new
            // 문제 조건: "T, S, Y를 이어붙인..." (여기서 Y는 겹치는게 제거된 Y)
            candidate = T + S + Y_new;
        }
        
        // 3. 길이 제한 확인
        if (candidate.length() > 20) {
            System.out.println(base);
        } else {
            System.out.println(candidate);
        }
    }
}
