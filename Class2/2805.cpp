#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> trees;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool IsPossible(unsigned int height, int n, int m) {
    unsigned int taken = 0;
    for (int i = 0; i < n; i++) {
        if (trees[i] >= height)
            taken += (trees[i] - height);
        if (taken >= m)
            return true;
    }
    return false;
}

int main() {
    TieCin();
    unsigned int n, m, input;
    unsigned int max = 0;
    vector<unsigned int> vec;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input;
        max = max < input ? input : max;
        trees.push_back(input);
    }

    unsigned int start = 0;
    unsigned int result = 0;
    unsigned int end = max;
    while (end >= start) {
        unsigned int mid = (start + end) / 2;
        if (IsPossible(mid, n, m)) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << result;
}
