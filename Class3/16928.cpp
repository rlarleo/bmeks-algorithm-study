#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[101] = {
    0,
};
vector<int> sadariInput;
vector<int> sadariOutput;

void Bfs(int start) {
    queue<pair<int, int>> que;
    que.push({start, 0});
    visited[start] = 1;
    while (!que.empty()) {
        int current = que.front().first;
        int step = que.front().second + 1;
        que.pop();
        for (int i = 1; i <= 6; i++) {
            int next = current + i;
            int sadariIndex =
                find(sadariInput.begin(), sadariInput.end(), next) -
                sadariInput.begin();

            if (sadariIndex != sadariInput.size()) {
                next = sadariOutput[sadariIndex];
            }

            if (!visited[next] && next <= 100) {
                if (next == 100) {
                    cout << step;
                    return;
                }
                visited[next] = 1;
                que.push({next, step});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int start, end;
        cin >> start >> end;
        sadariInput.push_back(start);
        sadariOutput.push_back(end);
    }

    Bfs(1);

    return 0;
}