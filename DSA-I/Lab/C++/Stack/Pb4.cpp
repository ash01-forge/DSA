#include <iostream>
#include <stack>
using namespace std;
class QueueUsingStacks
{
private:
    stack<int> s1, s2;

public:
    void Enqueue(int val)
    {
        s1.push(val);
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!\n";
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }
    void Display()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        stack<int> temp = s2;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    QueueUsingStacks q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Dequeue();
    q.Display();
    cout << (q.isEmpty() ? "True" : "False") << endl;
    return 0;
}