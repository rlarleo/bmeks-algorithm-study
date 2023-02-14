#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> stairs;
    vector<int> dp;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        stairs.push_back(input);
    }
    dp.push_back(stairs[0]);
    if (N > 1) {
        dp.push_back(stairs[1] + stairs[0]);
    }
    if (N > 2) {
        dp.push_back(max(stairs[2] + stairs[1], stairs[0] + stairs[2]));
    }

    for (int i = 3; i < N; i++) {
        dp.push_back(stairs[i] + max(dp[i - 3] + stairs[i - 1], dp[i - 2]));
    }
    cout << dp[N - 1];

    return 0;
}