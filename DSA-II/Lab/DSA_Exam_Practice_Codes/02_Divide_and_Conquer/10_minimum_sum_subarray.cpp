#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int>v;

/// PDF PROBLEM 7: Minimum Sum Subarray using Divide and Conquer
int minsum_subarray(int start,int _end)
{
    if(start==_end)
        return v[start];

    int mid=(start+_end)/2;
    int left_min=minsum_subarray(start,mid);
    int right_min=minsum_subarray(mid+1,_end);

    int left_middle_min=100000000;
    int current_sum=0;

    for(int i=mid;i>=start;i--)
    {
        current_sum+=v[i];
        left_middle_min=min(left_middle_min,current_sum);
    }

    int right_middle_min=100000000;
    current_sum=0;

    for(int i=mid+1;i<=_end;i++)
    {
        current_sum+=v[i];
        right_middle_min=min(right_middle_min,current_sum);
    }

    int merged_min=left_middle_min+right_middle_min;

    /// max became min, and negative infinity became positive infinity
    return min(merged_min,min(left_min,right_min));
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

    cout<<minsum_subarray(0,n-1)<<endl;
}
