#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> mySet;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    int n, m, input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        mySet.insert(input);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (mySet.find(input) != mySet.end())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
