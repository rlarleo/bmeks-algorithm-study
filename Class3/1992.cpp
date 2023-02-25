#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int N;
bool map[64][64];
string result = "";

bool IsPossible(int x, int y, int s) {
    int start = map[y][x];
    for (int i = y; i < y + s; i++) {
        for (int j = x; j < x + s; j++) {
            if (start != map[i][j]) {
                return false;
            }
        }
    }
    result = result + to_string(start);
    return true;
}

void Divide(int x, int y, int s) {
    if (IsPossible(x, y, s)) {
        return;
    } else {
        result = result + "(";
        Divide(x, y, s / 2);
        Divide(x + s / 2, y, s / 2);
        Divide(x, y + s / 2, s / 2);
        Divide(x + s / 2, y + s / 2, s / 2);
    }
    result = result + ")";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    Divide(0, 0, N);

    cout << result;
    return 0;
}
