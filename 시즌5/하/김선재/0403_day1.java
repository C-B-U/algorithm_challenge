import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 버퍼를 통해 입력

        HashMap<String, Integer> color = new HashMap<>(); // key value 사용하기 위해서 hashmap 이용

        //map에 key value 입력
        color.put("black" ,0); // key = black, vaule = 0
        color.put("brown" ,1);
        color.put("red" ,2);
        color.put("orange" ,3);
        color.put("yellow" ,4);
        color.put("green" ,5);
        color.put("blue" ,6);
        color.put("violet" ,7);
        color.put("grey" ,8);
        color.put("white" ,9);

        String c1 = Integer.toString(color.get(br.readLine())); // 첫번째 색의 값 (문자형)
        String c2 = Integer.toString(color.get(br.readLine())); // 두번째 색의 값 (문자형)
        long c3 = color.get(br.readLine()); // 세번째 색의 곲

        long result = Integer.parseInt(c1 + c2) * (long)(Math.pow(10, c3)); // (정수형 변환)(값+값) * 곱


        System.out.print(result); // 결과값 출력


        br.close(); // 입력 버퍼 닫아줌

        //pr 테스트
    }
}
