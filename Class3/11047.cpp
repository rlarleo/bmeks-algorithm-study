#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K, coin;
    vector<int> coins;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    int index = N - 1;
    int count = 0;
    while (K != 0) {
        if (coins[index] > K)
            index--;
        else {
            K = K - coins[index];
            count++;
        }
    }
    cout << count;
}
