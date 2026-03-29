import java.io.*;
import java.util.*;
 
public class Main {
	public static boolean[] prime;
    public static void get_prime() {
		// true = 소수아님 , false = 소수 
		prime[0] = prime[1] = true;
		
		for(int i = 2; i <= Math.sqrt(prime.length); i++) {        // 에라토스테네스의 체를 사용
			if(prime[i]) continue;
			for(int j = i * i; j < prime.length; j += i) {
				prime[j] = true;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));        // 버퍼 스트림을 통해 입력
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		StringBuilder stb = new StringBuilder();
        
        int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		prime = new boolean[N + 1];
		get_prime();
		
		for(int i = M; i <= N; i++) {
			// false = 소수 
			if(!prime[i]) stb.append(i).append('\n');
		}
        
		System.out.println(stb);
        br.close();        // 입력 버퍼 스트림 닫아줌
	}
}