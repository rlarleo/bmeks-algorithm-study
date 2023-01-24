#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }
    int result = 0;
    while (!pq.empty()) {
        result += (pq.top() * pq.size());
        pq.pop();
    }
    cout << result;

    return 0;
}