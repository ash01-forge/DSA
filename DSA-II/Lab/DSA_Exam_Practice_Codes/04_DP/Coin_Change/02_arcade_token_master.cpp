#include<iostream>
#include<algorithm>
using namespace std;

int game_type;
int ticket_value[1005];
int dp[100005];

/// PRACTICE PROBLEM 8: The Arcade Token Master
int solve(int rem_ticket)
{
    if(rem_ticket==0)
        return 0;

    if(dp[rem_ticket]!=-1)
        return dp[rem_ticket];

    int game_count=100000000;

    for(int i=0;i<game_type;i++)
    {
        if(ticket_value[i]<=rem_ticket)
        {
            int count=1+solve(rem_ticket-ticket_value[i]);
            game_count=min(game_count,count);
        }
    }

    dp[rem_ticket]=game_count;
    return game_count;
}

int main()
{
    cin>>game_type;

    for(int i=0;i<game_type;i++)
        cin>>ticket_value[i];

    int required_ticket;
    cin>>required_ticket;

    for(int i=0;i<=required_ticket;i++)
        dp[i]=-1;

    int answer=solve(required_ticket);

    if(answer>=100000000)
        cout<<-1<<endl;
    else
        cout<<answer<<endl;
}
