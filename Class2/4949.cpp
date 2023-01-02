#include <iostream>
#include <stack>

using namespace std;

void TieCin()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
}

bool IsPopable(char c, char stackTop)
{
    if(c == ')' && stackTop == '(') return true;
    else if(c == ']' && stackTop == '[') return true;
    return false;
}

void Output(int i, int wordLength, bool stackEmpty)
{
    if(i < wordLength) cout << "no" << endl;
    else if(stackEmpty) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main()
{
    TieCin();

    while(true)
    {
        stack<char> myStack;
        string words;

        getline(cin, words);

        if(words == ".") break;
        int i;
        for(i = 0; i < words.length(); i++)
        {
            if(words[i] == '(' || words[i] == '[') myStack.push(words[i]);
            else if(words[i] == ')' || words[i] == ']')
            {
                if(!myStack.empty() && IsPopable(words[i], myStack.top())) myStack.pop();
                else break;
            }
        }

        Output(i, words.length(), myStack.empty());

    }

    return 0;
}