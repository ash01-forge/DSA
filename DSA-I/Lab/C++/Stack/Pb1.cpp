#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}