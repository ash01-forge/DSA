#include <iostream>
#include <queue>
using namespace std;
class StackUsingQueues
{
private:
    queue<int> q1, q2;

public:
    void push(int val)
    {
        q2.push(val);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty!";
            return;
        }
        cout << "Popped Element:" << q1.front() << endl;
        q1.pop();
    }
    void top()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty!";
            return;
        }
        cout << "Top Element:" << q1.front() << endl;
    }
    void isEmpty()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty!";
        }
        else
            cout << "Stack is not Empty!";
        cout << endl;
    }
    void Display()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty!";
            return;
        }
        queue<int> temp = q1;
        cout << "Stack Elements:";
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    StackUsingQueues s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.Display();
    s.top();
    s.pop();
    s.top();
    s.Display();
    s.isEmpty();
    return 0;
}