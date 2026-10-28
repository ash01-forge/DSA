#include<iostream>
#include<algorithm>
using namespace std;

int n;
int weight[1005];
int value[1005];
int dp[1005][1005];

/// PRACTICE PROBLEM 5: The Mars Rover Payload
int solve(int current_item,int rem_capacity)
{
    if(current_item==n-1)
    {
        if(weight[current_item]<=rem_capacity)
            return value[current_item];
        else
            return 0;
    }

    /// This state was already calculated
    if(dp[current_item][rem_capacity]!=-1)
        return dp[current_item][rem_capacity];

    int taken=0;

    /// An item can be taken only if its full weight fits
    if(weight[current_item]<=rem_capacity)
    {
        taken=value[current_item]
              +solve(current_item+1,rem_capacity-weight[current_item]);
    }

    /// Moving to current_item+1 means this item cannot be used again
    int not_taken=solve(current_item+1,rem_capacity);

    int answer=max(taken,not_taken);
    dp[current_item][rem_capacity]=answer;

    return answer;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>weight[i]>>value[i];

    int capacity;
    cin>>capacity;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
            dp[i][j]=-1;
    }

    cout<<solve(0,capacity)<<endl;
}
