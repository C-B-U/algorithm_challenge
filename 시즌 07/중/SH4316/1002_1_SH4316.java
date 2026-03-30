import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public void run()
    {
        int size_x, size_y;
        String[] board;
        {
            String[] str = readline().split(" ");
            size_x = Integer.parseInt(str[1]);
            size_y = Integer.parseInt(str[0]);
        }

        board = new String[size_y];
        for(int i = 0; i < size_y; i++)
        {
            board[i] = readline();
        }

        int min = 5000;
        for(int i = 0; i <= size_y-8; i++)
        {
            for(int j = 0; j <= size_x-8; j++)
            {
                int num = check(board, j, i);
                if(num < min) min = num;
            }
        }

        print(min);
    }
    public int check(String[] board, int x_start, int y_start)
    {
        int result = 5000;
        boolean isBlack = false;

        for(int n = 0; n < 2; n++)
        {
            isBlack = !isBlack;
            int count = 0;
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(isBlack)
                    {
                        if(board[i+y_start].charAt(j+x_start) == 'W')
                        {
                            //print("is not black");
                            count++;
                        }
                        else
                        {
                            //print("is black");
                        }
                    }
                    else // isW
                    {
                        if(board[i+y_start].charAt(j+x_start) == 'B')
                        {
                            //print("is not white");
                            count++;
                        }
                        else
                        {
                            //print("is white");
                        }
                    }
                    isBlack = !isBlack;
                }
                isBlack = !isBlack;
            }
            if(result > count)  result = count;
        }
        return result;
    }


    public String readline()
    {
        try {
            return br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
    public static void print(long num){System.out.println(num);}
    public static void print(String str){System.out.println(str);}



    public static void main(String[] args) { new Main().run();}
}
