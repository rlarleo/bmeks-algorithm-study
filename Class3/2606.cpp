#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool network[101][101];
bool visited[101] = {
    0,
};
int N, M;

void Bfs() {
    queue<int> que;
    que.push(1);
    visited[1] = 1;
    while (!que.empty()) {
        int current = que.front();
        que.pop();
        for (int i = 1; i <= N; i++) {
            if (network[current][i] && !visited[i]) {
                visited[i] = 1;
                que.push(i);
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result += visited[i];
    }
    cout << result - 1;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        network[start][end] = 1;
        network[end][start] = 1;
    }

    Bfs();
    return 0;
}