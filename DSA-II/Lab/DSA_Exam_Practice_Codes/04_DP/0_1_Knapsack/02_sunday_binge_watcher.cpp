#include<iostream>
#include<algorithm>
using namespace std;

int movie_count;
int runtime[1005];
int rating[1005];
int dp[1005][1005];

/// PRACTICE PROBLEM 6: The Sunday Binge-Watcher
int solve(int current_movie,int rem_minutes)
{
    if(current_movie==movie_count-1)
    {
        if(runtime[current_movie]<=rem_minutes)
            return rating[current_movie];
        else
            return 0;
    }

    if(dp[current_movie][rem_minutes]!=-1)
        return dp[current_movie][rem_minutes];

    int watched=0;

    if(runtime[current_movie]<=rem_minutes)
    {
        watched=rating[current_movie]
                +solve(current_movie+1,rem_minutes-runtime[current_movie]);
    }

    int not_watched=solve(current_movie+1,rem_minutes);

    int answer=max(watched,not_watched);
    dp[current_movie][rem_minutes]=answer;

    return answer;
}

int main()
{
    cin>>movie_count;

    for(int i=0;i<movie_count;i++)
        cin>>runtime[i]>>rating[i];

    int free_hours;
    cin>>free_hours;

    /// Convert hours to minutes because movie runtimes are in minutes
    int available_minutes=free_hours*60;

    for(int i=0;i<=movie_count;i++)
    {
        for(int j=0;j<=available_minutes;j++)
            dp[i][j]=-1;
    }

    cout<<solve(0,available_minutes)<<endl;
}
