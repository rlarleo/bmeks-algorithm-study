#include <iostream>
#include <queue>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();

    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++) {
        queue<pair<int, int>> que;
        priority_queue<int> pq;

        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            que.push({j, input});
            pq.push(input);
        }
        int result = 1;
        while (true) {
            if (pq.top() == que.front().second) {
                if (que.front().first == m)
                    break;
                que.pop();
                pq.pop();
                result++;
            } else {
                que.push(que.front());
                que.pop();
            }
        }
        cout << result << endl;
    }

    return 0;
}
