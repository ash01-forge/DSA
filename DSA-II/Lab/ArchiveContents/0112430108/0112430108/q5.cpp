
#include<iostream>
#include<algorithm>
using namespace std;

int coin_type;
int coin_value[1005];
int dp[100005];


int solve(int rem_change)
{
    if(rem_change==0)
        return 0;

    if(dp[rem_change]!=-1)
        return dp[rem_change];

    int coin_count=100000000;

    for(int i=0;i<coin_type;i++)
    {
        if(coin_value[i]<=rem_change)
        {
            
            int count=1+solve(rem_change-coin_value[i]);
            coin_count=min(coin_count,count);
        }
    }

    dp[rem_change]=coin_count;
    return coin_count;
}

int main()
{
    cin>>coin_type;
    int change;
    cin>>change;

    for(int i=0;i<=change;i++)
        dp[i]=-1;

       

    for(int i=0;i<coin_type;i++)
        cin>>coin_value[i];


          int answer=solve(change);

   

    

    
    if(answer>=100000000)
        cout<<-1<<endl;
    else
        cout<<answer<<endl;
}
