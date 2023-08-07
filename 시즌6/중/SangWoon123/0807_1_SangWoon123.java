package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String temp[]=br.readLine().split(" ");

        long x = Integer.parseInt(temp[0]);
        long y = Integer.parseInt(temp[1]);
        long w = Integer.parseInt(temp[2]);
        long s = Integer.parseInt(temp[3]);

        long case1 = (x + y) * w;
        long case2;
        long case3 = (Math.min(x, y) * s) + (Math.abs(x - y) * w);


        if((x + y) % 2 == 0) {
            case2 = Math.max(x, y) * s;
        } else {
            case2 = (Math.max(x, y) - 1) * s + w;
        }



        System.out.println(Math.min(Math.min(case1, case2), case3));
    }

}