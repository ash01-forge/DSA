#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>>requests;

/// PRACTICE PROBLEM 2: The Telescope Scheduler
bool custom_sort(pair<int,int>a,pair<int,int>b)
{
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
        requests.push_back(make_pair(start_time,end_time));
    }

    sort(requests.begin(),requests.end(),custom_sort);

    int approved=0;
    int current_finish_time=-100000000;

    for(int i=0;i<n;i++)
    {
        if(requests[i].first>=current_finish_time)
        {
            approved++;
            current_finish_time=requests[i].second;
        }
    }

    cout<<approved<<endl;
}
