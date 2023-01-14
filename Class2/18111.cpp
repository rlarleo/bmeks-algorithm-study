#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int map[501][501];
    int n, m, b, input;
    int max = 0;
    int min = 500;
    int result = INT_MAX;
    int result_h = INT_MAX;
    cin >> n >> m >> b;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input;
            map[i][j] = input;
            max = max < input ? input : max;
            min = min > input ? input : min;
        }
    }
    
    for(int height = min; height <= max; height++){
        int inven = b;
        int move = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int curr = map[i][j];
                if(curr > height){
                    move = move + 2 * (curr - height);
                    inven = inven + (curr - height);
                }
                else if(curr < height){
                    move = move + (height - curr);
                    inven = inven - (height - curr);
                }
            }
        }
        if(inven < 0) break;
        else {
            result = result > move ? move : result;
            result_h = result >= move ? height : result_h;
        }
    }
    cout << result << " " << result_h;

    return 0;
}