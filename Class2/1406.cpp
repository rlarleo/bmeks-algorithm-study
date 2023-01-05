#include <iostream>
#include <stack>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    deque<char> left;
    deque<char> right;
    string s;
    int n;
    cin >> s >> n;

    for (int i = 0; i < s.length(); i++) {
        left.push_back(s[i]);
    }
    for (int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
        case 'L':
            if (!left.empty()) {
                right.push_front(left.back());
                left.pop_back();
            }
            break;
        case 'D':
            if (!right.empty()) {
                left.push_back(right.front());
                right.pop_front();
            }
            break;
        case 'B':
            if (!left.empty()) {
                left.pop_back();
            }
            break;
        case 'P':
            char c;
            cin >> c;
            left.push_back(c);
            break;
        default:
            break;
        }
    }

    while (!left.empty()) {
        cout << left.front();
        left.pop_front();
    }
    while (!right.empty()) {
        cout << right.front();
        right.pop_front();
    }

    return 0;
}
