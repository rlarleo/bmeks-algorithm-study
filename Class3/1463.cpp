#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);

    for (int i = 4; i <= n; i++) {
        int divide3 = INT_MAX;
        int divide2 = INT_MAX;
        int minus1 = INT_MAX;
        if (i % 3 == 0)
            divide3 = vec[i / 3] + 1;
        if (i % 2 == 0)
            divide2 = vec[i / 2] + 1;
        minus1 = vec[i - 1] + 1;
        int divideMin = min(divide3, divide2);
        int result = min(divideMin, minus1);
        vec.push_back(result);
    }

    cout << vec[n];
    return 0;
}