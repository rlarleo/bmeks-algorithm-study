#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

char map[3 * 1024][6 * 1024] = {
    ' ',
};

void Draw(int x, int y) {
    map[y][x] = '*';
    map[y + 1][x - 1] = '*';
    map[y + 1][x + 1] = '*';
    for (int i = x - 2; i < x + 3; i++) {
        map[y + 2][i] = '*';
    }
}

void Divide(int n, int x, int y) {
    if (n == 3) {
        Draw(x, y);
        return;
    }
    Divide(n / 2, x, y);
    Divide(n / 2, x - n / 2, y + n / 2);
    Divide(n / 2, x + n / 2, y + n / 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            map[i][j] = ' ';
        }
    }
    Divide(n, n - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}