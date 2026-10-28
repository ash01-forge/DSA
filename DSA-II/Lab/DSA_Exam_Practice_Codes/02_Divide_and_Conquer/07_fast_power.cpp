#include<iostream>
using namespace std;

/// PDF PROBLEM 5: Calculate b^n using Divide and Conquer
long long calculate_power(long long b,int n)
{
    if(n==0)
        return 1;

    long long half_answer=calculate_power(b,n/2);

    /// Calculate b^(n/2) only once, then reuse it
    if(n%2==0)
        return half_answer*half_answer;
    else
        return half_answer*half_answer*b;
}

int main()
{
    long long b;
    int n;
    cin>>b>>n;

    cout<<calculate_power(b,n)<<endl;
}
