#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    set<int> temp;
    set<int> s;

    for (int i = 1; i <= 20; i++)
        temp.insert(i);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        int input;
        cin >> cmd;
        if (cmd == "add") {
            cin >> input;
            s.insert(input);
        } else if (cmd == "remove") {
            cin >> input;
            if (s.find(input) != s.end())
                s.erase(s.find(input));
        } else if (cmd == "check") {
            cin >> input;
            if (s.find(input) != s.end())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (cmd == "toggle") {
            cin >> input;
            if (s.find(input) != s.end())
                s.erase(s.find(input));
            else
                s.insert(input);
        } else if (cmd == "all") {
            s = temp;
        } else if (cmd == "empty") {
            s.clear();
        }
    }

    return 0;
}