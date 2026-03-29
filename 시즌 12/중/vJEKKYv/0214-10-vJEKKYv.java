package main;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // 입력 받기
        int N = input.nextInt(); // 단어의 개수
        int M = input.nextInt(); // 목표 길이
        input.nextLine(); // 개행 문자 처리

        ArrayList<String> arrayList = new ArrayList<>();
        int allSize = 0;

        // 단어들 입력받고, 총 길이 계산
        for (int i = 0; i < N; i++) {
            String str = input.nextLine();
            arrayList.add(str);
            allSize += str.length();
        }

        // 기본적으로 각 단어 사이에 들어갈 _의 개수
        int cnt = (M - allSize) / (N - 1);
        int tm = (M - allSize) % (N - 1); // 남은 _의 개수

        // 각 단어 사이에 기본적으로 _을 넣기 위한 준비
        String line = "";
        for (int i = 0; i < cnt; i++) {
            line += "_";
        }

        // 기본 _을 각 단어 사이에 배치
        for (int i = 0; i < arrayList.size() - 1; i++) {
            arrayList.set(i, arrayList.get(i) + line);
        }

        // 남은 _을 소문자로 시작하는 단어들에 먼저 배분
        boolean flag = false;
        if ((M - allSize) % (N - 1) != 0) {
            for (int i = 1; i < arrayList.size(); i++) {
                if (arrayList.get(i).charAt(0) >= 'a' && arrayList.get(i).charAt(0) <= 'z') {
                    arrayList.set(i - 1, arrayList.get(i - 1) + "_");
                    tm--;
                }
                if (tm == 0) {
                    flag = true;
                    break;
                }
            }

            // 만약 여전히 남은 _이 있다면 대문자 시작 단어에 배분
            if (!flag) {
                for (int i = arrayList.size() - 1; i > 0; i--) {
                    if (arrayList.get(i).charAt(0) >= 'A' && arrayList.get(i).charAt(0) <= 'Z') {
                        arrayList.set(i - 1, arrayList.get(i - 1) + "_");
                        tm--;
                    }
                    if (tm == 0) {
                        break;
                    }
                }
            }
        }

        // 결과 출력
        for (int i = 0; i < arrayList.size(); i++) {
            System.out.print(arrayList.get(i));
        }

        input.close(); // Scanner 자원 해제
    }
}
