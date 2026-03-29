import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
		Scanner kb = new Scanner(System.in);
		while(true){
			String str = kb.nextLine();
			if(str.equals("#")) break;
			String[] arr = str.toLowerCase().split("");
			int count = 0;
			for(int i = 0; i < arr.length; i++){
				if(str.split(" ")[0].equals(arr[i])) count++;
			}
			System.out.println(str.split(" ")[0] + " " + (count-1));
		}
		kb.close();
	}
}
