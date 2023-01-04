#include <iostream>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    int x, y, w, h;
    int minX = 1000;
    int minY = 1000;
    int result = 0;

    cin >> x >> y >> w >> h;

    minX = x < w - x ? x : w - x;
    minY = y < h - y ? y : h - y;
    result = minX < minY ? minX : minY;

    cout << result;

    return 0;
}
