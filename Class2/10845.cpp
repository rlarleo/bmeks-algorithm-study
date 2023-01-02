#include <iostream>
#include <queue>
#include <string>

using namespace std;

void TieCin()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
}

int main()
{
    TieCin();

    int n;
    cin >> n;
    queue<int> myQueue;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        
        if(cmd == "push"){
            int s;
            cin >> s;
            myQueue.push(s);
        }
        else if(cmd == "front"){
            if(myQueue.size() == 0) cout << -1 << endl;
            else cout << myQueue.front() << endl;
        }
        else if(cmd == "back"){
            if(myQueue.size() == 0) cout << -1 << endl;
            else cout << myQueue.back() << endl;
        }
        else if(cmd == "size"){
            cout << myQueue.size() << endl;
        }
        else if(cmd == "pop"){
            if(myQueue.size() == 0) cout << -1 << endl;
            else {
                cout << myQueue.front() << endl;
                myQueue.pop();
            }
        }
        else if(cmd == "empty"){
            if(myQueue.size() == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}

