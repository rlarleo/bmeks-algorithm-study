#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
string input;
int map[25][25] = {
    0,
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
priority_queue<int, vector<int>, greater<int>> pq;

bool IsValid(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

void Bfs(int y, int x) {
    int count = 1;
    queue<pair<int, int>> que;
    que.push({y, x});
    map[y][x] = 0;
    while (!que.empty()) {
        int curr_y = que.front().first;
        int curr_x = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];
            if (IsValid(next_x, next_y) && map[next_y][next_x]) {
                map[next_y][next_x] = 0;
                que.push({next_y, next_x});
                count++;
            }
        }
    }

    pq.push(count);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j])
                Bfs(i, j);
        }
    }

    cout << pq.size() << '\n';
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}
