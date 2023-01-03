#include <iostream>
#include <queue>
#include <string>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();

    int n;
    cin >> n;
    deque<int> myDeque;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        int s;
        if (cmd == "push_front") {
            cin >> s;
            myDeque.push_front(s);
        } else if (cmd == "push_back") {
            cin >> s;
            myDeque.push_back(s);
        } else if (cmd == "pop_front") {
            if (myDeque.empty())
                cout << -1 << endl;
            else {
                cout << myDeque.front() << endl;
                myDeque.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (myDeque.empty())
                cout << -1 << endl;
            else {
                cout << myDeque.back() << endl;
                myDeque.pop_back();
            }
        } else if (cmd == "size") {
            cout << myDeque.size() << endl;
        } else if (cmd == "empty") {
            if (myDeque.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if (cmd == "front") {
            if (myDeque.empty())
                cout << -1 << endl;
            else
                cout << myDeque.front() << endl;
        } else if (cmd == "back") {
            if (myDeque.empty())
                cout << -1 << endl;
            else
                cout << myDeque.back() << endl;
        }
    }

    return 0;
}
