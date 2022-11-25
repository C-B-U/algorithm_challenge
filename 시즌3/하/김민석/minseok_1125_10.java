import java.util.Scanner;

public class minseok_1125_10 {
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        int x1=scan.nextInt();
        int y1=scan.nextInt();
        int x2=scan.nextInt();
        int y2=scan.nextInt();
        int x3=scan.nextInt();
        int y3=scan.nextInt();

        double disA=distance(x1-x2,y1-y2);
        double disB=distance(x1-x3,y1-y3);
        double disC=distance(x2-x3,y2-y3);

        double MaxDis,MinDis;
        MaxDis=Math.max(Math.max(disA,disB),disC);
        MinDis=Math.min(Math.min(disA,disB),disC);

        double inclination1=999999;
        double inclination2=999999;

        if(y1!=y2) inclination1=(double)(x1-x2)/(double)(y1-y2);
        if(y2!=y3) inclination2=(double)(x2-x3)/(double)(y2-y3);

        if(inclination1==inclination2){
            System.out.println("-1");
        }else{
            System.out.println(2*(MaxDis-MinDis));
        }
    }
    public static double distance(int X,int Y){
        return Math.sqrt(Math.pow(X,2)+Math.pow(Y,2));
    }
}
