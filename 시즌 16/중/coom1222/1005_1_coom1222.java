import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 입력값 읽기 (한 줄에 모두 주어짐)
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        long W = Long.parseLong(st.nextToken()); // 종이 너비
        long H = Long.parseLong(st.nextToken()); // 종이 높이
        long f = Long.parseLong(st.nextToken()); // 접는 선의 x좌표
        long c = Long.parseLong(st.nextToken()); // 가로로 접는 횟수
        long x1 = Long.parseLong(st.nextToken()); // 색칠 영역 x1
        long y1 = Long.parseLong(st.nextToken()); // 색칠 영역 y1
        long x2 = Long.parseLong(st.nextToken()); // 색칠 영역 x2
        long y2 = Long.parseLong(st.nextToken()); // 색칠 영역 y2
        
        // 1. 색칠된 높이(Length Y) 계산
        // 세로로는 (c+1)개의 구간이 완벽하게 겹쳐지므로, 칠한 높이에 (c+1)을 곱하면 됨
        long paintHeight = (y2 - y1) * (c + 1);
        
        // 2. 색칠된 너비(Length X) 계산
        // 접는 선 f가 접힌 종이의 x=0 (왼쪽 끝)이 됨.
        // 따라서 접힌 종이는 두 개의 층(Layer)으로 구성됨을 알 수 있음.
        // Layer 1: 원래 종이의 왼쪽 부분 (길이 f) -> 접힌 좌표계 [0, f]
        // Layer 2: 원래 종이의 오른쪽 부분 (길이 W-f) -> 접힌 좌표계 [0, W-f]
        
        // 칠하는 범위 [x1, x2]가 각 Layer와 얼마나 겹치는지 계산
        
        // Layer 1과의 교집합 길이
        // 범위: [0, f] 와 [x1, x2] 의 교집합
        long overlap1 = 0;
        if (x1 < f) {
            overlap1 = Math.min(x2, f) - x1;
        }
        
        // Layer 2과의 교집합 길이
        // 범위: [0, W-f] 와 [x1, x2] 의 교집합
        long overlap2 = 0;
        if (x1 < (W - f)) {
            overlap2 = Math.min(x2, (W - f)) - x1;
        }
        
        long paintWidth = overlap1 + overlap2;
        
        // 3. 전체 넓이와 색칠된 넓이 계산
        // W, H가 최대 10^9이므로 곱셈 결과는 long 범위를 사용해야 함 (이미 long으로 선언됨)
        long totalArea = W * H;
        long coloredArea = paintWidth * paintHeight;
        
        // 색칠되지 않은 영역 출력
        System.out.println(totalArea - coloredArea);
    }
}
