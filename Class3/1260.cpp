#include <iostream>
#include <queue>

using namespace std;
int n, m, v;
int result = 0;
int graph[1001][1001] = {
    0,
};
bool visited[1001] = {
    0,
};

void init() {
    for (int i = 1; i < 1001; i++) {
        visited[i] = 0;
    }
    cout << endl;
}

void Dfs(int v) {
    visited[v] = 1;
    cout << v << ' ';
    for (int i = 1; i < 1001; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void Bfs(int v) {
    queue<int> que;
    que.push(v);
    while (!que.empty()) {
        int current = que.front();
        if (visited[current]) {
            que.pop();
            continue;
        }
        cout << current << ' ';
        visited[current] = 1;
        que.pop();
        for (int i = 1; i < 1001; i++) {
            if (graph[current][i] && !visited[i]) {
                que.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    Dfs(v);
    init();
    Bfs(v);
    return 0;
}