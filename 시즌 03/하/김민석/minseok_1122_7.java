//우유 축제 : https://www.acmicpc.net/problem/14720

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class minseok_1122_7 {
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        int N=scan.nextInt();
        int ans=0;
        int ary[]={0,1,2};
        int index=0;
        Queue<Integer> que=new LinkedList<>();
        for(int i=0;i<N;i++){
            int data=scan.nextInt();
            que.add(data);
        }
        for(int i=0;i<N;i++){
            if(que.poll()==ary[index]){
                ans++;
                index++;
                if(index==3) index=0;
            }
        }
        System.out.print(ans);
    }
}
