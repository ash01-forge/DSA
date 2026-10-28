#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    int arr[100];
    int topI = -1;

public:
    void push(int val)
    {
        topI++;
        arr[topI] = val;
    }
    void pop()
    {
        topI--;
    }
    int top()
    {
        return arr[topI];
    }
    bool empty()
    {
        return topI == -1;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}