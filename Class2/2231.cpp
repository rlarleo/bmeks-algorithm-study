#include <iostream>
#include <string>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int divideSum(int n) {
    int sum = n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    TieCin();

    int n;
    cin >> n;

    int i;
    for (i = 0; i < 1000000; i++) {
        int result = divideSum(i);
        if (result == n) {
            cout << i;
            break;
        }
    }
    if (i == 1000000)
        cout << 0;

    return 0;
}