import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        int D = scanner.nextInt();

        int[][] grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }

        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int y = R, x = C;
        int cleaned = 0;

        while (true) {
            if (grid[y][x] == 0) {
                grid[y][x] = -1;
                cleaned++;
                continue;
            }

            boolean aroundCleaned = true;
            for (int[] dir : directions) {
                int ny = y + dir[0];
                int nx = x + dir[1];
                if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                    if (grid[ny][nx] == 0) {
                        aroundCleaned = false;
                        break;
                    }
                }
            }

            if (aroundCleaned) {
                int[] Dir = directions[D];
                int ny = y - Dir[0];
                int nx = x - Dir[1];

                if (!(ny >= 0 && ny < N && nx >= 0 && nx < M)) {
                    break;
                }

                if (grid[ny][nx] == 1) {
                    break;
                }

                y = ny;
                x = nx;
                continue;
            }

            for (int i = 0; i < 4; i++) {
                D--;
                if (D < 0) { D = 3; }

                int[] dir = directions[D];
                int ny = y + dir[0];
                int nx = x + dir[1];

                if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                    if (grid[ny][nx] == 0) {
                        y = ny;
                        x = nx;
                        break;
                    }
                }
            }
        }

        System.out.println(cleaned);
        scanner.close();
    }
}
