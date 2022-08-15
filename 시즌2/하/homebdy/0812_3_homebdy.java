import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class homebey_3 {

    private static class Location {
        int x, y;

        public Location(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // 미로 생성
        int mazeSize = scanner.nextInt();
        int[][] maze = new int[mazeSize][mazeSize];
        boolean[][] visit = new boolean[mazeSize][mazeSize];
        for (int i=0; i<mazeSize; i++) {
            for (int j=0; j<mazeSize; j++) {
                maze[i][j] = scanner.nextInt();
                visit[i][j] = false;
            }
        }

        int[] dx = {1, 0};
        int[] dy = {0, 1};
        //BFS
        Queue<Location> queue = new LinkedList<>();
        queue.add(new Location(0, 0));

        while(!queue.isEmpty()) {
            Location location = queue.poll();
            if(maze[location.x][location.y] == -1) {
                System.out.println("HaruHaru");
                return;
            }
            visit[location.x][location.y] = true;
            for (int i=0; i<2; i++) {
                int nextX = location.x + dx[i]*maze[location.x][location.y];
                int nextY = location.y + dy[i]*maze[location.x][location.y];
                if (nextX >= mazeSize || nextY >= mazeSize || visit[nextX][nextY] == true) {
                    continue;
                }
                queue.add(new Location(nextX, nextY));
            }
        }
        System.out.println("Hing");
    }
}