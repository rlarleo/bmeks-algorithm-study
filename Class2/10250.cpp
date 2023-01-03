#include <iostream>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void Output(int x, int y) {
    if (y < 10)
        cout << x << '0' << y << endl;
    else
        cout << x << y << endl;
}

int main() {
    TieCin();

    int test, height, width, host;
    int x, y;

    cin >> test;

    for (int i = 0; i < test; i++) {
        cin >> height >> width >> host;

        x = host % height ? host % height : height;
        y = (host - 1) / height + 1;

        Output(x, y);
    }

    return 0;
}