#include<iostream>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

/// CLASS EXAMPLE: Basic operations of stack, queue and deque
int main()
{
    stack<int>s;
    queue<int>q;
    deque<int>dq;

    s.push(15);
    s.push(16);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    q.push(15);
    q.push(16);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;

    dq.push_back(14);
    dq.push_back(15);
    dq.push_front(6);
    dq.push_back(7);

    cout<<dq.front()<<" "<<dq.back()<<endl;

    dq.pop_back();
    dq.pop_front();

    cout<<dq.front()<<" "<<dq.back()<<endl;
}
