#include <iostream>
#include <vector>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool IsPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= n / 2; i++) {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

int main() {
    TieCin();
    int n;
    int result = 0;
    cin >> n;
    vector<bool> primes;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (IsPrime(input))
            result++;
    }

    cout << result;

    return 0;
}
