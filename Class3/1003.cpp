#include <iostream>
#include <vector>

using namespace std;
vector<int> fi0;
vector<int> fi1;

void init() {
    fi0.push_back(1);
    fi0.push_back(0);
    fi0.push_back(1);
    fi0.push_back(1);
    fi1.push_back(0);
    fi1.push_back(1);
    fi1.push_back(1);
    fi1.push_back(2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int max = 0;
    vector<int> vec;

    init();

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
        max = max < input ? input : max;
    }

    for (int i = 4; i <= max; i++) {
        fi0.push_back(fi0[i - 1] + fi0[i - 2]);
        fi1.push_back(fi1[i - 1] + fi1[i - 2]);
    }

    for (auto v : vec) {
        cout << fi0[v] << ' ' << fi1[v] << '\n';
    }

    return 0;
}