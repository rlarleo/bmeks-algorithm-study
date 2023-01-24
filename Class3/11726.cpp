#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> vec;
    int N;
    cin >> N;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    for (int i = 3; i <= N; i++) {
        vec.push_back((vec[i - 2] + vec[i - 1]) % 10007);
    }
    cout << vec[N];
    return 0;
}