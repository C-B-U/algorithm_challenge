import java.util.Scanner;

public class Day1 {
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int MW=scan.nextInt();
        int MB=scan.nextInt();
        int TW=scan.nextInt();
        int TB=scan.nextInt();
        int PW=scan.nextInt();
        int PB=scan.nextInt();
        int minBlack=MB,minWhite=MW;
        //검흰검(1)->흰검흰(2)  or 흰검흰 -> 검흰검
        //검흰검이 먼저오는경우
        if(MB>TW){
            if(TW>PB){
                minBlack=PB;
            }else{
                minBlack=TW;
            }
        }else{
            if(MB>PB){
                minBlack=PB;
            }else{
                minBlack=MB;
            }
        }
        if(MW>TB){
            if(TB>PW){
                minWhite=PW;
            }else{
                minWhite=TB;
            }
        }else{
            if(MW>PW){
                minWhite=PW;
            }else{
                minWhite=MW;
            }
        }
        if(minWhite<minBlack){
            System.out.println(minWhite*2+1);
        }
        else if(minWhite==minBlack){
            System.out.println(minWhite*2);
        }
        else{
            System.out.println(minBlack*2+1);
        }

    }

}
