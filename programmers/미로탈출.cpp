#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
string test1[5] = {"OOESL", "XXXXO", "OOOOO", "OXXXX", "OOOOO"};
string test2[5] = {"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int currentStep = 0;

char map[100][100];

bool leverOn = false;

int visited[100][100] = {
    0,
};

bool IsValid(int x, int y, int mX, int mY) {
    return x >= 0 && x < mX && y >= 0 && y < mY && visited[y][x] == 0;
}

void InitVisited() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visited[i][j] = 0;
        }
    }
}

int Bfs(pair<int, int> start, int mY, int mX) {
    visited[start.first][start.second] = 1;
    queue<pair<int, int>> que;
    que.push(start);
    while (!que.empty()) {
        int curr_x = que.front().second;
        int curr_y = que.front().first;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if (IsValid(next_x, next_y, mX, mY) && map[next_y][next_x] != 'X') {
                visited[next_y][next_x] = visited[curr_y][curr_x] + 1;
                if (map[next_y][next_x] == 'L') {
                    leverOn = true;
                    map[next_y][next_x] = 'O';
                    currentStep = visited[next_y][next_x];
                    InitVisited();
                    while (!que.empty()) {
                        que.pop();
                    }
                    visited[next_y][next_x] = 1;
                    que.push({next_y, next_x});
                    break;
                }
                if (leverOn && map[next_y][next_x] == 'E') {
                    return visited[next_y][next_x] + currentStep - 2;
                }

                que.push({next_y, next_x});
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    pair<int, int> start;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S')
                start = {i, j};
            map[i][j] = maps[i][j];
        }
    }

    return Bfs(start, maps.size(), maps[0].size());
}

int main() {
    vector<string> test;
    for (int i = 0; i < 5; i++) {
        test.push_back(test1[i]);
    }
    cout << solution(test);
    return 0;
}
