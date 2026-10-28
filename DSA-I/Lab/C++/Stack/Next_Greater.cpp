#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {6, 8, 0, 1, 3};
    stack<int> s;
    vector<int> ans(v.size(), 0);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
            ans[i] = s.top();

        s.push(v[i]);
    }
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}