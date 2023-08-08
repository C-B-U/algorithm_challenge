package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long num=Long.parseLong(br.readLine());
        long count=Long.parseLong(br.readLine());

        if(num==1){
            System.out.println(num*8);
        }else if(num==5){
            System.out.println(num*8+4);
        }else{
            if(count%2==0){
                System.out.println(4*count+1+(2-num));
            }else{
                System.out.println(4*count+1+(4-num));
            }
        }

        // 참고: https://zoosso.tistory.com/135





    }

}