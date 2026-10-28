#include <iostream>
#include <stack>
using namespace std;
void findMiddle(stack<int> &s)
{
    int size = s.size();
    for (int i = 0; i < size / 2; i++)
    {
        s.pop();
    }
    cout <<"Middle Element:" <<s.top() << " ";
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    findMiddle(s);
}