import java.util.Scanner;

class homebdy_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int[] list = new int[num];
        for (int i=0; i<num; i++) {
            list[i] = scanner.nextInt();
        }
        for (int i=0; i<num-1; i++) {
            for (int j=i+1; j<num; j++) {
                if (list[i] > list[j]) {
                    int temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
        for (int i=0; i<num; i++)
            System.out.println(list[i]);
    }
}
