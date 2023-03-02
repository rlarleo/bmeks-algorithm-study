#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int map[20][20] = {
    0,
};
bool visited[20][20] = {
    0,
};
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int N;

bool IsValid(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
bool IsMovable(int babySize, int currSize) { return babySize >= currSize; }

void InitVisit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}
void Bfs(pair<int, int> start) {
    queue<pair<pair<int, int>, int>> que;
    que.push({start, 0});
    pair<int, int> babySize = {2, 0};
    visited[start.first][start.second] = 1;
    while (!que.empty()) {
        int curr_x = que.front().first.second;
        int curr_y = que.front().first.first;
        int move = que.front().second;
        que.pop();
        bool isContinue = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] < babySize.first && map[i][j] != 0) {
                    isContinue = true;
                }
            }
        }
        if (!isContinue) {
            cout << move;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            int next = map[next_y][next_x];
            if (IsValid(next_x, next_y) && IsMovable(babySize.first, next) &&
                !visited[next_y][next_x]) {
                cout << next_y << " " << next_x << endl;
                if (next < babySize.first && next != 0) {
                    cout << "hi: " << next_y << " " << next_x << " " << move + 1
                         << endl;
                    map[next_y][next_x] = 0;
                    babySize.second++;
                    while (!que.empty()) {
                        que.pop();
                    }
                    que.push({{next_y, next_x}, move + 1});
                    visited[next_y][next_x] = 1;
                    InitVisit();
                    break;
                }
                visited[next_y][next_x] = 1;
                que.push({{next_y, next_x}, move + 1});
            }
        }
        if (babySize.first <= babySize.second) {
            babySize.first++;
            babySize.second = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cin >> N;
    pair<int, int> start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if (input == 9) {
                start = {i, j};
                continue;
            }
            map[i][j] = input;
        }
    }

    Bfs(start);
    return 0;
}
