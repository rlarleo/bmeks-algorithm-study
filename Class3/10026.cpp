#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

char map[100][100];
bool visited[100][100] = {
    0,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;

bool IsValid(int x, int y) { return (x >= 0 && x < N && y >= 0 && y < N); }

void Bfs(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = 1;
    while (!que.empty()) {
        pair<int, int> current = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if (IsValid(nextX, nextY) && !visited[nextX][nextY] &&
                map[current.first][current.second] == map[nextX][nextY]) {
                que.push({nextX, nextY});
                visited[nextX][nextY] = 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        string color;
        cin >> color;
        for (int j = 0; j < N; j++) {
            map[i][j] = color[j];
        }
    }

    int count1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                Bfs(i, j);
                count1++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
            if (map[i][j] == 'R')
                map[i][j] = 'G';
        }
    }

    int count2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                Bfs(i, j);
                count2++;
            }
        }
    }
    cout << count1 << ' ' << count2;

    return 0;
}