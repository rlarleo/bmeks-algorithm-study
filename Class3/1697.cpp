

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
unsigned int visited[100001] = {
    0,
};

void Bfs() {
    queue<int> que;
    que.push(N);
    visited[N] = 1;
    while (!que.empty()) {
        int current = que.front();
        que.pop();
        int next = current * 2;
        if (next <= 100000 && visited[next] == 0) {
            visited[next] = visited[current] + 1;
            que.push(next);
        }
        if (next == K)
            break;
        next = current - 1;
        if (next >= 0 && visited[next] == 0) {
            visited[next] = visited[current] + 1;
            que.push(next);
        }
        if (next == K)
            break;
        next = current + 1;
        if (next <= 100000 && visited[next] == 0) {
            visited[next] = visited[current] + 1;
            que.push(next);
        }
        if (next == K)
            break;
    }
    cout << visited[K] - 1;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    Bfs();

    return 0;
}