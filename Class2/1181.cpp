#include <iostream>
#include <set>

using namespace std;

void TieCin() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Compare {
    bool operator()(const string &a, const string &b) const {
        if (a.length() == b.length())
            return a < b;
        return a.length() < b.length();
    }
};

int main() {
    TieCin();
    int n;
    string word;
    set<string, Compare> sets;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> word;
        sets.insert(word);
    }

    for (auto s : sets) {
        cout << s << endl;
    }

    return 0;
}
