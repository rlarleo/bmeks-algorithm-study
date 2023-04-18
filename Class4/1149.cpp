#include <cmath>
#include <iostream>

using namespace std;
int n, r, c;
int result = 0;

void Z(int x, int y, int size) {
    if ((x == c && y == r)) {
        cout << result;
        return;
    }
    if (c >= x && c < x + size && r >= y && r < y + size) {
        Z(x, y, size / 2);
        Z(x + size / 2, y, size / 2);
        Z(x, y + size / 2, size / 2);
        Z(x + size / 2, y + size / 2, size / 2);
    } else {
        result = result + size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;

    Z(0, 0, pow(2, n));

    return 0;
}