import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String []s = new String[n];
        boolean []check = new boolean[26];
        in.nextLine();
        for(int i=0;i<n;i++){
            s[i]=in.nextLine();
        }
        for(int i=0;i<s.length;i++){
            if(s[i].contains(" ")){
                boolean flag = false;
                String []ss = s[i].split(" ");
                for(int j=0;j<ss.length;j++){
                    if(!check[Character.toUpperCase(ss[j].charAt(0)) - 65]){
                        check[Character.toUpperCase(ss[j].charAt(0)) - 65]=true;
                        ss[j] = "["+ss[j].substring(0,1)+"]"+ss[j].substring(1);
                        flag = true;
                        break;
                    }
                }
                s[i] = String.join(" ",ss);
                if(!flag){
                    for(int j=0;j<s[i].length();j++){
                        if(s[i].charAt(j)!=' '){
                            if(!check[Character.toUpperCase(s[i].charAt(j)) - 65]){
                                check[Character.toUpperCase(s[i].charAt(j)) - 65] = true;
                                s[i] = s[i].substring(0,j)+"["+s[i].substring(j,j+1)+"]"+s[i].substring(j+1);
                                break;
                            }
                        }
                    }
                }
            }
            else {
                for(int j=0;j<s[i].length();j++){
                    if(!check[Character.toUpperCase(s[i].charAt(j)) - 65]){
                        check[Character.toUpperCase(s[i].charAt(j)) - 65]=true;
                        s[i] = s[i].substring(0,j)+"["+s[i].substring(j,j+1)+"]"+s[i].substring(j+1);
                        break;
                    }
                }
            }
        }
        for(int i=0;i<s.length;i++){
            System.out.println(s[i]);
        }
    }
}