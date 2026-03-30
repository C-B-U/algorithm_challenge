import java.util.Scanner;

public class Main {
    static int [][]num;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        num= new int[n][n];
        for(int i=0;i<n;i++){
            String s = in.next();
            for(int j=0;j<n;j++){
                num[i][j]=s.charAt(j)-'0';
            }
        }
        tree(0,0,n);
        System.out.println(sb);
    }
    static boolean check(int x, int y, int size){
        int checkNum = num[x][y];
        for(int i=x;i<x+size;i++){
            for(int j=y;j<y+size;j++){
                if(checkNum!=num[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    static void tree(int x, int y, int size){
        if(check(x,y,size)){
            sb.append(num[x][y]);
            return;
        }
        int newSize = size/2;
        sb.append("(");
        tree(x, y, newSize);
        tree(x,y+newSize,newSize);
        tree(x+newSize,y,newSize);
        tree(x+newSize,y+newSize,newSize);
        sb.append(")");
    }
}