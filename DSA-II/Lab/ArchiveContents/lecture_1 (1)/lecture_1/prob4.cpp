#include<iostream>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

int main()
{
    /*
    stack<int>s;
    queue<int>q;

    s.push(15);
    s.push(16);

    q.push(15);
    q.push(16);

    cout<<s.top()<<endl;
    cout<<q.front()<<endl;

    s.pop();
    q.pop();
    cout<<s.top()<<endl;
    cout<<q.front()<<endl;
    */

    deque<int>dq;
    dq.push_back(14);
    dq.push_back(15); //(14,15)
    dq.push_front(6); // (6,14,15)
    dq.push_back(7); // (6,14,15,7)
    cout<<dq.front()<<endl; // 6
    cout<<dq.back()<<endl;// 7
    dq.pop_back(); // (6,14,15)
    dq.pop_front(); // (14,15)
    cout<<dq.front()<<endl;





}
