#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long dp[101] = {
    0,
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, N, max = 0;
    vector<int> vec;
    cin >> T;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for (int i = 0; i < T; i++) {
        cin >> N;
        vec.push_back(N);
        max = max < N ? N : max;
    }

    for (int i = 6; i <= max; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    for (auto v : vec) {
        cout << dp[v] << '\n';
    }

    return 0;
}
