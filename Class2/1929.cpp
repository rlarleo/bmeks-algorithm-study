#include <iostream>
#include <vector>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    int n, m;
    cin >> n >> m;
    vector<bool> primes;
    for (int i = 0; i <= m; i++) {
        primes.push_back(true);
    }

    for (int i = 2; i <= m; i++) {
        if (primes[i] == true) {
            if (i >= n)
                cout << i << '\n';
            for (int j = i * 2; j <= m; j += i) {
                primes[j] = false;
            }
        }
    }

    return 0;
}
