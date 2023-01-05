#include <iostream>
#include <vector>

using namespace std;

vector<int> lopes;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int CountOfLopes(int mid) {
    int count = 0;
    for (auto l : lopes) {
        count += l / mid;
    }
    return count;
}

int main() {
    TieCin();
    int n, m;
    long long totalLength = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        long long lope;
        cin >> lope;
        totalLength += lope;
        lopes.push_back(lope);
    }

    long long start = 1;
    long long end = totalLength / m;
    long long mid;
    int result = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        int count = CountOfLopes(mid);
        if (count >= m) {
            start = mid + 1;
            if (result < mid)
                result = mid;
        } else {
            end = mid - 1;
        }
    }
    cout << result << endl;

    return 0;
}
