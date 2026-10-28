#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v;

/// PDF PROBLEM 6: Count numbers that are multiples of 3 or 5
int multiple_count(int start,int _end)
{
    if(start==_end)
    {
        /// Use OR because a number matching either condition is counted once
        if(v[start]%3==0 || v[start]%5==0)
            return 1;
        else
            return 0;
    }

    int mid=(start+_end)/2;
    int left_count=multiple_count(start,mid);
    int right_count=multiple_count(mid+1,_end);

    return left_count+right_count;
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

    cout<<multiple_count(0,n-1)<<endl;
}
