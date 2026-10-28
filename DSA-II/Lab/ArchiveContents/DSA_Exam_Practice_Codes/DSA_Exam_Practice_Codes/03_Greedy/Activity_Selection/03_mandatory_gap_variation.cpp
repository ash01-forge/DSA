#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>>works;

/// ACTIVITY SELECTION VARIATION: Keep a mandatory gap between works
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
        works.push_back(make_pair(start_time,end_time));
    }

    int gap;
    cin>>gap;

    sort(works.begin(),works.end(),custom_sort);

    int taken=0;
    int next_possible_start=-100000000;

    for(int i=0;i<n;i++)
    {
        if(works[i].first>=next_possible_start)
        {
            taken++;

            /// After taking a work, wait gap units before the next one
            next_possible_start=works[i].second+gap;
        }
    }

    cout<<taken<<endl;
}
