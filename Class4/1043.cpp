#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> knows;
int parent[51];
vector<vector<int>> parties(50);

int FindParent(int x) {
    if (x != parent[x])
        return parent[x] = FindParent(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int parentX = FindParent(parent[x]);
    int parentY = FindParent(parent[y]);
    if (parentX != parentY) {
        if (parentX < parentY)
            parent[parentY] = parent[parentX];
        else
            parent[parentX] = parent[parentY];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < K; i++) {
        int know;
        cin >> know;
        // 진실을 아는 사람들의 집합 -> 0
        parent[know] = 0;
    }

    for (int i = 0; i < M; i++) {
        int S, person, prev;
        cin >> S;
        for (int j = 0; j < S; j++) {
            if (j >= 1) {
                prev = person;
                cin >> person;
                Union(prev, person);
            } else {
                cin >> person;
            }
            parties[i].push_back(person);
        }
    }

    int result = M;
    for (auto party : parties) {
        for (auto person : party) {
            if (FindParent(parent[person]) == 0) {
                result--;
                break;
            }
        }
    }
    cout << result;

    return 0;
}
