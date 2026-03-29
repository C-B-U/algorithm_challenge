#include <stdio.h>

int main() {
        
    int grid[50][50];
    int N, M, R, C, D;
    int direcs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &R, &C, &D);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int y = R, x = C;
    int dy, dx, ny, nx;
    int cleaned = 0;
    
    while (1) {
        if (grid[y][x] == 0) {
            grid[y][x] = -1;
            cleaned++;
            continue;
        }
        
        int around_cleaned = 1;
        for (int i = 0; i < 4; i++) {
            ny = y + direcs[i][0];
            nx = x + direcs[i][1];
            
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (grid[ny][nx] == 0) {
                    around_cleaned = 0;
                    break;
                }
            }
        }
        
        if (around_cleaned) {
            dy = direcs[D][0];
            dx = direcs[D][1];
            ny = y - dy;
            nx = x - dx;
            
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
            dy = direcs[D][0];
            dx = direcs[D][1];
            ny = y + dy;
            nx = x + dx;
            
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (grid[ny][nx] == 0) {
                    y = ny;
                    x = nx;
                    break;
                }
            }
        }
    }
    
    printf("%d\n", cleaned);
    
    return 0;
}