import java.util.Scanner;

public class Main {

    public static void repairBlock(char[][] grid, int N, int M, int y, int x) {
        int center_y = y * 3 + 1;
        int center_x = x * 3 + 1;
        boolean checked = false;

        if (x > 0) {
            char left = grid[center_y][center_x - 2];
            if (left == '#') {
                grid[center_y][center_x - 1] = '#';
                checked = true;
            }
        }

        if (x < M - 1) {
            char right = grid[center_y][center_x + 2];
            if (right == '#') {
                grid[center_y][center_x + 1] = '#';
                checked = true;
            }
        }

        if (y > 0) {
            char up = grid[center_y - 2][center_x];
            if (up == '#') {
                grid[center_y - 1][center_x] = '#';
                checked = true;
            }
        }

        if (y < N - 1) {
            char down = grid[center_y + 2][center_x];
            if (down == '#') {
                grid[center_y + 1][center_x] = '#';
                checked = true;
            }
        }

        if (checked) grid[center_y][center_x] = '#';
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine();

        char[][] grid = new char[N * 3][M * 3];
        for (int i = 0; i < N * 3; i++) {
            grid[i] = scanner.nextLine().toCharArray();
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                repairBlock(grid, N, M, y, x);
            }
        }

        for (char[] line : grid) {
            System.out.println(new String(line));
        }
    }
}