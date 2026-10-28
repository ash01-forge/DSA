#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// CLASS PROBLEM: Rank teams by highest total health
bool custom_sort(pair<int,int>a,pair<int,int>b)
{
    /// true means a will stay before b
    if(a.first+a.second>b.first+b.second)
        return true;
    else if(a.first+a.second==b.first+b.second)
        return a.first>b.first;
    else
        return false;
}

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>>teams;

    for(int i=0;i<n;i++)
    {
        int first_health,second_health;
        cin>>first_health>>second_health;
        teams.push_back(make_pair(first_health,second_health));
    }

    sort(teams.begin(),teams.end(),custom_sort);

    for(int i=0;i<teams.size();i++)
    {
        cout<<teams[i].first<<" "<<teams[i].second<<endl;
    }
}
