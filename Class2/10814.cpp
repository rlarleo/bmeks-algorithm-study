#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    vector<tuple<int, int, string>> vec;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        vec.push_back(make_tuple(age, i, name));
    }

    sort(vec.begin(), vec.end());
    for (auto v : vec) {
        cout << get<0>(v) << " " << get<2>(v) << '\n';
    }

    return 0;
}
