#include <iostream>
#include <string>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool IsAvailableTitle(int t) {
    string title = to_string(t);
    return title.find("666") != string::npos;
}

int main() {
    TieCin();

    int n;
    int count = 0;
    cin >> n;

    int title = 666;

    while (true) {
        if (IsAvailableTitle(title)) {
            count++;
            if (n == count) {
                cout << title;
                break;
            }
        }
        title++;
    }

    return 0;
}