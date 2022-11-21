import java.util.Scanner;

public class minseok_1121_6 {
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        String tmp=scan.next();



        final String end="end";
        while(!tmp.equals(end)){
            boolean check1=false;
            boolean check2=true;
            int cnt=0;
            String[] ary=new String[20];
            ary=tmp.split("");

            for(int i=0;i<tmp.length();i++){
                if(vowel(ary[i])==1){
                    check1=true;
                }
                if(i!=0&&ary[i].equals(ary[i-1])){
                    if(ary[i].equals("e")||ary[i].equals("o")){
                        check2=true;
                    }
                    else{
                        check2=false;
                        break;
                    }
                }
                if(i!=0){
                    if(vowel(ary[i])==1&&vowel(ary[i-1])==1){
                        cnt++;
                    }
                    else if(vowel(ary[i])==-1&&vowel(ary[i-1])==-1){
                        cnt++;
                    }
                    else{
                        cnt=0;
                    }
                }
                if(cnt>=2){
                    check2=false;
                    break;
                }
            }
            if(check1==true &&check2==true){
                System.out.println("<"+tmp+"> is acceptable.");
            }else{
                System.out.println("<"+tmp+"> is not acceptable.");
            }
            tmp= scan.next();
        }


    }
    public static int vowel(String a){
        if(a.equals("a")||a.equals("e")||a.equals("i")||a.equals("o")||a.equals("u")){
            return 1;
        }
        else{
            return -1;
        }
    }
}
