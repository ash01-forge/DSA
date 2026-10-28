#include<iostream>
using namespace std;

int coin_type;
int coin_value[1005];
long long dp[100005];

/// COIN CHANGE VARIATION: Count ordered ways
/// 1+2 and 2+1 are counted as two different ways
long long solve(int rem_change)
{
    if(rem_change==0)
        return 1;

    if(dp[rem_change]!=-1)
        return dp[rem_change];

    long long total_ways=0;

    for(int i=0;i<coin_type;i++)
    {
        if(coin_value[i]<=rem_change)
        {
            /// Choosing a different first coin creates a different order
            total_ways+=solve(rem_change-coin_value[i]);
        }
    }

    dp[rem_change]=total_ways;
    return total_ways;
}

int main()
{
    cin>>coin_type;

    for(int i=0;i<coin_type;i++)
        cin>>coin_value[i];

    int change;
    cin>>change;

    for(int i=0;i<=change;i++)
        dp[i]=-1;

    cout<<solve(change)<<endl;
}
