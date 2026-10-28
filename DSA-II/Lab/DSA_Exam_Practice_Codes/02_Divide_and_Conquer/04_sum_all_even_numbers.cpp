#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v;

/// PDF PROBLEM 2: Sum of all even numbers using Divide and Conquer
int even_sum(int start,int _end)
{
    if(start==_end)
    {
        if(v[start]%2==0)
            return v[start];
        else
            return 0;
    }

    int mid=(start+_end)/2;
    int left_sum=even_sum(start,mid);
    int right_sum=even_sum(mid+1,_end);

    /// Merge: total even sum is the sum of both answers
    return left_sum+right_sum;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    cout<<even_sum(0,n-1)<<endl;
}
