import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 입력 처리
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken()); // 토카와 집 사이 거리
        long B = Long.parseLong(st.nextToken()); // 토카의 초기 이동 거리
        
        st = new StringTokenizer(br.readLine());
        long C = Long.parseLong(st.nextToken()); // 토카와 돌돌이 사이 거리
        long D = Long.parseLong(st.nextToken()); // 돌돌이의 이동 거리
        
        long K = Long.parseLong(br.readLine());  // 피로도 (이동 거리 감소량)
        
        long result = solve(A, B, C, D, K);
        System.out.println(result);
    }
    
    private static long solve(long A, long B, long C, long D, long K) {
        long N = -1;
        
        // 1. 토카가 집에 도착하는 최소 횟수 N 계산
        if (K == 0) {
            // 속도가 줄지 않는 경우: ceil(A / B)
            N = (A + B - 1) / B;
        } else {
            // 속도가 줄어드는 경우
            // 속도가 0보다 클 때까지만 유효한 이동 (속도 > 0  =>  B - (m-1)K > 0)
            long m = (B - 1) / K + 1;
            
            // 최대로 이동해도 집에 못 가면 -1
            if (calcDist(m, B, K) < A) return -1;
            
            // 이분 탐색으로 A 이상 가는 최소 N 찾기
            long low = 1, high = m;
            while (low <= high) {
                long mid = (low + high) / 2;
                if (calcDist(mid, B, K) >= A) {
                    N = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        // 2. 잡힘 여부 확인
        
        // 조건 A: 첫 이동 후 잡히는가? (시작하자마자 잡히는 경우)
        // 토카 이동: B, 돌돌 이동: D. 
        // 격차가 C였으므로, B + C <= D 이면 잡힘 (토카위치 <= 돌돌위치)
        if (B + C <= D) return -1;
        
        // 조건 B: 집에 도착했을 때(N) 잡히는가? (동시 도착 포함)
        // 돌돌이가 N번 이동해서 간 거리가 (A+C) 이상이면 잡힘
        // (N * D >= A + C)를 오버플로우 없이 비교하기 위해 나눗셈 활용
        long dolArrivalSteps = (A + C + D - 1) / D; // 돌돌이가 집에 도착하는 횟수
        if (N >= dolArrivalSteps) return -1;
        
        // 조건 C: 집에 도착하기 직전(N-1)에 잡히는가?
        // N=1이면 위 조건들로 충분함
        if (N > 1) {
            if (isCaughtAt(N - 1, B, C, D, K)) return -1;
        }
        
        return N;
    }
    
    // N번 이동했을 때 토카의 총 이동 거리
    private static long calcDist(long n, long B, long K) {
        // 등차수열 합 공식: n*B - {n*(n-1)/2}*K
        return n * B - n * (n - 1) / 2 * K;
    }
    
    // 특정 step에서 잡혔는지 확인
    private static boolean isCaughtAt(long step, long B, long C, long D, long K) {
        // K=0일 때 오버플로우 방지 로직
        if (K == 0) {
            if (D <= B) return false; // 토카가 더 빠르면 절대 안 잡힘 (중간엔)
            // C <= step * (D - B) 인지 확인
            // 즉, step >= ceil(C / (D-B))
            long limit = (C + (D - B) - 1) / (D - B);
            return step >= limit;
        } else {
            // K > 0인 경우 step은 최대 20억 정도이므로 long 범위 내 계산 가능
            long tokaDist = calcDist(step, B, K);
            long doldolDist = step * D;
            // 토카 위치(출발점 기준): A - tokaDist
            // 돌돌 위치(출발점 기준): A + C - doldolDist
            // 돌돌 위치 <= 토카 위치 => (A+C-doldolDist) <= (A-tokaDist)
            // => C + tokaDist <= doldolDist 이면 잡힘
            return C + tokaDist <= doldolDist;
        }
    }
}
