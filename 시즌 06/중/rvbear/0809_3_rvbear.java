import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));           // 버퍼 스트림을 통해 입력
        int n = Integer.parseInt(br.readLine());            // 숫자의 개수
        int[] arr = new int[n];                             // 값을 저장할 배열
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);                                   // 배열 정렬

        for(int i = arr.length-3; i >= 0; i--) {            // 배열의 마지막 부분부터 탐색 시작
            // 가장 긴 변의 길이가 다른 두 변의 길이의 합보다 작을 경우 삼각형 만들 수 있음
            if(arr[i]+arr[i+1] > arr[i+2]) {                
                // 만들 수 있는 가장 긴 세 변의 합은 가장 처음 if문에 들어오는 값
                System.out.println(arr[i] + arr[i+1] + arr[i+2]);
                return;
            }
        }

        System.out.println(-1);                             // 만들어지는 값이 없다면 -1 출력
        br.close();                                         // 입력 버퍼 스트림 닫아줌
    }
}