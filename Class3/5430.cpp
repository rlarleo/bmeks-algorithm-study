#include <deque>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

deque<int> split(string str, char Delimiter) {
    str = str.substr(1, str.size() - 2);
    istringstream iss(str);
    string buffer;
    deque<int> result;

    while (getline(iss, buffer, Delimiter)) {
        if (buffer != "")
            result.push_back(stoi(buffer));
    }

    return result;
}

void Output(bool isReverse, deque<int> deque) {
    cout << '[';
    while (!deque.empty()) {
        if (isReverse) {
            cout << deque.back();
            deque.pop_back();
        } else {
            cout << deque.front();
            deque.pop_front();
        }
        if (!deque.empty())
            cout << ',';
    }
    cout << ']' << '\n';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, s;
    string P, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> P >> s >> N;
        deque<int> deque = split(N, ',');
        bool isReverse = false;
        bool isError = false;
        for (int j = 0; j < P.size(); j++) {
            if (P[j] == 'R') {
                isReverse = !isReverse;
            } else {
                if (!deque.empty()) {
                    if (!isReverse) {
                        deque.pop_front();
                    } else {
                        deque.pop_back();
                    }
                } else {
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
            }
        }
        if (!isError)
            Output(isReverse, deque);
    }
    return 0;
}