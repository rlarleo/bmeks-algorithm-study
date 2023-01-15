#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool map[51][51] = {
    0,
};

int t, n, m, k;
int result = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = 0;
        }
    }
    result = 0;
}

void Bfs(int x, int y) {
    map[x][y] = 0;
    queue<pair<int, int>> que;
    que.push(pair<int, int>(x, y));

    while (!que.empty()) {
        int curr_x = que.front().first;
        int curr_y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                if (map[next_x][next_y]) {
                    map[next_x][next_y] = 0;
                    que.push({next_x, next_y});
                }
            }
        }
    }
    result++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int l = 0; l < t; l++) {
        init();
        cin >> n >> m >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) {
                    Bfs(i, j);
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}