#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENPAIS 100
#define MAX_WEEKS 10
#define MAX_DAYS 7

typedef struct {
    char Name[51];
    int Price;
} SENPAI;

typedef struct {
    int dayOfYear;  // (W - 1) * 7 + D
    SENPAI senpai;
} SenpaiEntry;

int N;
SenpaiEntry Senpais[MAX_SENPAIS];
int Moneys[100];  // 예를 들어 100명의 인물을 저장할 수 있다고 가정
char Names[100][51];
bool Visited[MAX_WEEKS][MAX_DAYS];
int Answer;

int findNameIndex(const char* name) {
    for (int i = 0; i < N; i++) {
        if (strcmp(Names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void input() {
    int moneyCount = 0;

    // 읽기: Senpai 정보
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char name[51];
        int W, D, P;
        scanf("%s %d %d %d", name, &W, &D, &P);
        int dayOfYear = (W - 1) * 7 + D;
        SENPAI senpai = { 0 };
        strcpy(senpai.Name, name);
        senpai.Price = P;
        Senpais[i] = (SenpaiEntry){ dayOfYear, senpai };

        // 저장: 이름 목록과 인덱스
        bool found = false;
        for (int j = 0; j < moneyCount; j++) {
            if (strcmp(Names[j], name) == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(Names[moneyCount], name);
            moneyCount++;
        }
    }

    // 정렬
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (Senpais[i].dayOfYear > Senpais[j].dayOfYear) {
                SenpaiEntry temp = Senpais[i];
                Senpais[i] = Senpais[j];
                Senpais[j] = temp;
            }
        }
    }

    // 읽기: 돈 정보
    for (int i = 0; i < moneyCount; i++) {
        int P;
        scanf("%s %d", Names[i], &P);
        Moneys[i] = P;
    }
}

void settings() {
    memset(Visited, false, sizeof(Visited));
    
    for (int i = 0; i < N; i++) {
        int Week = Senpais[i].dayOfYear / 7;
        int Day = Senpais[i].dayOfYear % 7;
        char* Name = Senpais[i].senpai.Name;
        int Price = Senpais[i].senpai.Price;
        int index = findNameIndex(Name);

        if (index != -1 && Moneys[index] >= Price) {
            Visited[Week][Day] = true;
            Moneys[index] = -1;  // 방문 처리
        }
    }

    int Max_Day = 0;
    for (int i = 0; i < MAX_WEEKS; i++) {
        for (int j = 0; j < MAX_DAYS; j++) {
            if (Visited[i][j]) {
                Max_Day++;
            } else {
                if (Max_Day > Answer) {
                    Answer = Max_Day;
                }
                Max_Day = 0;
            }
        }
    }
    if (Max_Day > Answer) {
        Answer = Max_Day;
    }
}

void find_Answer() {
    printf("%d\n", Answer);
}

int main() {
    input();
    settings();
    find_Answer();
    return 0;
}