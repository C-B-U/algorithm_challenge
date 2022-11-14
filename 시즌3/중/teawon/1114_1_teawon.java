package teawon;

import java.util.*;
import java.io.*;
/*
 * 문제 주소 :  https://www.acmicpc.net/problem/1764
 * 26296KB | 288ms
 *  
 * 문제 접근 방법 & 사용 알고리즘: 
 * 1) 처음에는 HashMap을 사용하려했으나 굳이 맵을 사용할 필요가없었다. 왜냐하면 중복여부만 확인하면되니까
 * -> HashSet을 사용
 **/

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();

        List<String> result = new ArrayList<>();

        int N = Integer.parseInt(st.nextToken()); // 듣도 못한 사람 수
        int M = Integer.parseInt(st.nextToken()); // 보도 못한 사람 수

        HashSet<String> set = new HashSet<>(); // 각 이름을 키로가지는 해시셋 생성
        int count = 0;

        for (int i = 0; i < N; i++) {
            String name = br.readLine();
            set.add(name);
        }

        for (int i = 0; i < M; i++) {
            String name = br.readLine();
            if (set.contains(name)) {
                result.add(name);
                count++;
            }

        }

        Collections.sort(result); // 오름차순으로 정렬

        for (int i = 0; i < result.size(); i++) {
            sb.append("\n" + result.get(i));
        }

        System.out.print(count);
        System.out.println(sb);
    }

}
