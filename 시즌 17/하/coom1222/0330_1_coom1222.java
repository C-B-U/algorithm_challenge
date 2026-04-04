import java.util.*;

public class main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        if (s.contains("A")) {
            // A가 있으면 B, C, D, F를 모두 A로 변경
            s = s.replaceAll("[BCDF]", "A");
        } 
        else if (s.contains("B")) {
            // A가 없고 B가 있으면 C, D, F를 모두 B로 변경
            s = s.replaceAll("[CDF]", "B");
        } 
        else if (s.contains("C")) {
            // A, B가 없고 C가 있으면 D, F를 모두 C로 변경
            s = s.replaceAll("[DF]", "C");
        } 
        else {
            // A, B, C가 모두 없다면 모든 문자를 A로 변경
            s = s.replaceAll(".", "A");
        }

        System.out.println(s);
    }
}
