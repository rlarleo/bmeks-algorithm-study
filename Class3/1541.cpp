#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<char> calc;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            calc.push('-');
            s[i] = '+';
        }
        if (s[i] == '+')
            calc.push('+');
    }
    vector<string> nums = split(s, '+');

    int result = stoi(nums[0]);
    bool flag = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (flag || calc.front() == '-') {
            result = result - stoi(nums[i]);
            flag = 1;
        } else {
            result = result + stoi(nums[i]);
        }
        calc.pop();
    }

    cout << result;

    return 0;
}