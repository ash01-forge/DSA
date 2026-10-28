#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int>v;

/// MAIN CODE: Maximum Sum Subarray using Divide and Conquer
int maxsum_subarray(int start,int _end)
{
    if(start==_end)
        return v[start];

    int mid=(start+_end)/2;
    int left_max=maxsum_subarray(start,mid);
    int right_max=maxsum_subarray(mid+1,_end);

    int left_middle_max=-100000000;
    int current_sum=0;

    /// Best sum that must end at mid
    for(int i=mid;i>=start;i--)
    {
        current_sum+=v[i];
        left_middle_max=max(left_middle_max,current_sum);
    }

    int right_middle_max=-100000000;
    current_sum=0;

    /// Best sum that must start at mid+1
    for(int i=mid+1;i<=_end;i++)
    {
        current_sum+=v[i];
        right_middle_max=max(right_middle_max,current_sum);
    }

    int merged_max=left_middle_max+right_middle_max;

    /// Best subarray is left, right, or crosses the middle
    return max(merged_max,max(left_max,right_max));
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

    cout<<maxsum_subarray(0,n-1)<<endl;
}
