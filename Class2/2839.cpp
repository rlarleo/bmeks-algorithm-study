#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void init() {
    vec.push_back(5000); // 0
    vec.push_back(5000); // 1
    vec.push_back(5000); // 2
    vec.push_back(1);    // 3
    vec.push_back(5000); // 4
    vec.push_back(1);    // 5
}

int main() {
    TieCin();
    int n;

    cin >> n;

    init();

    for (int i = 6; i <= n; i++) {
        if (vec[i - 5] > vec[i - 3])
            vec.push_back(vec[i - 3] + 1);
        else
            vec.push_back(vec[i - 5] + 1);
    }
    if (vec[n] >= 5000)
        cout << -1;
    else
        cout << vec[n];
}
