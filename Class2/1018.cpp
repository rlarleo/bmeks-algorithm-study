#include <iostream>
#include <string>
#define MAX_N = 50;
#define MAX_M = 50;
using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    char WB[50][50];
    char myWB[50][50];

    int result = 32;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0)
                WB[i][j] = 'W';
            else
                WB[i][j] = 'B';
        }
    }

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            myWB[i][j] = row[j];
        }
    }

    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int diff = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (WB[k][l] == myWB[k + i][l + j])
                        diff++;
                }
            }
            if (diff > 32)
                diff = 64 - diff;

            result = result > diff ? diff : result;
        }
    }

    cout << result;

    return 0;
}
