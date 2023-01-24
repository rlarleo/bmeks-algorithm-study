#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int M, N, tomato;
int graph[1000][1000];
queue<pair<int, int>> que;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, -1, 1};

bool isValid(int x, int y) { return (x >= 0 && x < M && y >= 0 && y < N); }

void bfs() {
    while (!que.empty()) {
        pair<int, int> current = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int dx = current.second + x[i];
            int dy = current.first + y[i];
            if (isValid(dx, dy) && graph[dy][dx] == 0) {
                que.push({dy, dx});
                graph[dy][dx] = graph[current.first][current.second] + 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato;
            graph[i][j] = tomato;
            if (graph[i][j] == 1)
                que.push({i, j});
        }
    }

    bfs();

    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                cout << -1;
                return 0;
            }
            max = graph[i][j] > max ? graph[i][j] : max;
        }
    }

    cout << max - 1;

    return 0;
}