#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N, M;
string name;
set<string> names;
priority_queue<string, vector<string>, greater<string>> results;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> name;
        names.insert(name);
    }
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (names.find(name) != names.end())
            results.push(name);
    }
    cout << results.size() << '\n';
    while (!results.empty()) {
        cout << results.top() << '\n';
        results.pop();
    }

    return 0;
}