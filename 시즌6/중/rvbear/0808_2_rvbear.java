import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));       // 버퍼 스트림을 통해 입력
        long n = Long.parseLong(br.readLine());         // 다친 손가락
        long k = Long.parseLong(br.readLine());         // 다친 손가락을 사용할 수 있는 횟수
        long count = 0;                                 // 셀 수 있는 숫자

        if(n == 1) {                                    // 엄지가 다쳤을 경우
            count = (long)(k*8);
        } else if(n == 2) {                             // 검지가 다쳤을 경우
            count = (long)(1+(k/2)*8+(k%2)*6);
        } else if(n == 3) {                             // 중지가 다쳤을 경우
            count = (long)(2+(k/2)*8+(k%2)*4);
        } else if(n == 4) {                             // 약지가 다쳤을 경우
            count = (long)(3+(k/2)*8+(k%2)*2);
        } else {                                        // 새끼가 다쳤을 경우
            count = (long)(4+k*8);
        }

        System.out.println(count);                      // 결과값 출력
        br.close();                                     // 입력 버퍼 스트림 닫아줌
    }
}