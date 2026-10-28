#include <iostream>
#include <stack>
using namespace std;
class Parenthesis
{
public:
    bool isValid(string str)
    {
        stack<char> st;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                st.push(str[i]);
            }
            else
            {
                if (st.size() == 0)
                {
                    return false;
                }
                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
int main()
{
    Parenthesis p;
    string str;
    cout << "Enter your Parenthesis:" << endl;
    cin >> str;

    if (p.isValid(str))
    {
        cout << "Valid Parenthesis";
    }
    else
    {
        cout << "Invalid Parenthesis";
    }
    return 0;
}