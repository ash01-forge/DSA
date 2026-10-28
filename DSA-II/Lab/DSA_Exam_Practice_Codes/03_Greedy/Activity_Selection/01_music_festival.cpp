#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>>performances;

/// PRACTICE PROBLEM 1: The Music Festival
bool custom_sort(pair<int,int>a,pair<int,int>b)
{
    /// The performance that ends earlier must come first
    if(a.second<b.second)
        return true;
    else
        return false;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int start_time,end_time;
        cin>>start_time>>end_time;
        performances.push_back(make_pair(start_time,end_time));
    }

    sort(performances.begin(),performances.end(),custom_sort);

    int watched=0;
    int current_finish_time=-100000000;

    for(int i=0;i<n;i++)
    {
        /// Equality is allowed: one show may start when another ends
        if(performances[i].first>=current_finish_time)
        {
            watched++;
            current_finish_time=performances[i].second;
        }
    }

    cout<<watched<<endl;
}
