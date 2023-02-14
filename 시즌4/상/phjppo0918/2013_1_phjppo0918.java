package org.example.bruteforce.bj1111;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String [] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    
        int size = Integer.parseInt(st.nextToken());
        int[] s = Arrays
                .stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
        boolean finish;
        if(size == 1 || (size == 2 && s[0] != s[1])) {
            sb.append("A");
        }else if(size == 2) {
            sb.append(s[0]);
        }else {
            int num1;
            int num2;
            if(s[1] == s[0])   {
                num1 = 1;
                num2 = 0;
            }else {
                num1 = (s[2]-s[1])/(s[1]-s[0]);
                num2 = s[1]-(s[0]*num1);
            }

            if(accept(num1, num2, s)) {
                sb.append(s[size - 1] * num1 + num2);
            }else {
                sb.append("B");
            }
        }
        bw.write(sb.toString());
    
        bw.flush();
        br.close();
        bw.close();
    }

    private static boolean accept(int num1, int num2, int[] arr) {
        for(int i=0; i<arr.length - 1; i++) {
            if(arr[i+1] != (arr[i]*num1+num2) )
                return false;
        }
        return true;
    }

}
