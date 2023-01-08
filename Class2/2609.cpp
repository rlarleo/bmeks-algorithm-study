#include <iostream>
#include <queue>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int Gcd(int a, int b) {
    int n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int Lcm(int a, int b) { return a * b / Gcd(a, b); }

int main() {
    TieCin();
    int n, m;
    cin >> n >> m;

    cout << Gcd(n, m) << endl;
    cout << Lcm(n, m) << endl;

    return 0;
}
