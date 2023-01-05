#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> lopes;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    TieCin();
    int n, input;
    stack<int> myStack;
    vector<int> vec;
    vector<char> result;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        vec.push_back(input);
    }

    int curr = 1;
    int currIndex = 0;

    while (currIndex < n) {
        if (curr > n + 1) {
            cout << "NO";
            return 0;
        }
        if (!myStack.empty() && myStack.top() == vec[currIndex]) {
            currIndex++;
            myStack.pop();
            result.push_back('-');
        } else {
            myStack.push(curr);
            result.push_back('+');
            curr++;
        }
    }

    for (auto r : result) {
        cout << r << '\n';
    }

    return 0;
}
