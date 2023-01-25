#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int arr[12] = {
    0,
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= 11; i++) {
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << arr[N] << '\n';
    }

    return 0;
}