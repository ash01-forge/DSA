#include<iostream>
#include<stack>
using namespace std;
bool IsPalindrome(string s){
    stack<char>st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]!=st.top())
        {
            return false;
        }
        st.pop();
    }
    return true;
}
int main(){
    string s;
    cin>> s;
    if (IsPalindrome(s))
    {
        cout<<"Palindrome";
    }
    else cout<<"Not Palindrome";
    return 0;
}