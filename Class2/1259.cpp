#include <iostream>
#include <string>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void IsPalindrome(int n) {
    string number = to_string(n);
    for (int i = 0; i < number.length() / 2; i++) {
        if (number[i] != number[number.length() - i - 1]) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

int main() {
    TieCin();

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        IsPalindrome(n);
    }

    return 0;
}