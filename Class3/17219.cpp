#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;
int N, M;

map<string, string> sites;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string site, pw;
        cin >> site >> pw;
        sites.insert({site, pw});
    }

    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;
        auto it = sites.find(site);
        cout << it->second << '\n';
    }

    return 0;
}
