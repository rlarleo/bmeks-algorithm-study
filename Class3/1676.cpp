

#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, int> poketmons;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int result = 0;
    for (int i = 2; i <= n; i++) {
        int current = i;
        while (current % 5 == 0) {
            current /= 5;
            result++;
        }
    }
    cout << result;
    return 0;
}