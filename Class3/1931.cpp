#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int lastTime = 0;
int result = 0;

bool Cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void CheckTime(pair<int, int> input) {
    if (input.first >= lastTime) {
        result++;
        lastTime = input.second;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    vector<pair<int, int>> times;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        times.push_back({s, e});
    }

    sort(times.begin(), times.end(), Cmp);

    for (auto t : times) {
        // cout << t.first << " " << t.second << endl;
        CheckTime(t);
    }
    cout << result;

    return 0;
}
