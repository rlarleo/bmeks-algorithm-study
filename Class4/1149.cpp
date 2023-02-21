#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dpR;
vector<int> dpG;
vector<int> dpB;
vector<int> vecR;
vector<int> vecG;
vector<int> vecB;

int main() {
    cin.tie(NULL);
    int N, r, g, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> r >> g >> b;
        vecR.push_back(r);
        vecG.push_back(g);
        vecB.push_back(b);
    }
    dpR.push_back(vecR[0]);
    dpG.push_back(vecG[0]);
    dpB.push_back(vecB[0]);

    for (int i = 1; i < N; i++) {
        dpR.push_back(vecR[i] + min(dpG[i - 1], dpB[i - 1]));
        dpG.push_back(vecG[i] + min(dpR[i - 1], dpB[i - 1]));
        dpB.push_back(vecB[i] + min(dpR[i - 1], dpG[i - 1]));
    }

    cout << min(dpR[N - 1], min(dpG[N - 1], dpB[N - 1]));
    return 0;
}
