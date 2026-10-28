#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>>supplies;

/// PRACTICE PROBLEM 4: Disaster Relief Airdrop
/// pair<weight,survival_utility>
bool custom_sort(pair<int,int>a,pair<int,int>b)
{
    float utility_per_weight_a=(float)a.second/a.first;
    float utility_per_weight_b=(float)b.second/b.first;

    if(utility_per_weight_a>utility_per_weight_b)
        return true;
    else
        return false;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int weight,utility;
        cin>>weight>>utility;
        supplies.push_back(make_pair(weight,utility));
    }

    float remaining_weight;
    cin>>remaining_weight;

    sort(supplies.begin(),supplies.end(),custom_sort);

    float total_utility=0;

    for(int i=0;i<n;i++)
    {
        if(supplies[i].first<=remaining_weight)
        {
            total_utility+=supplies[i].second;
            remaining_weight-=supplies[i].first;
        }
        else if(remaining_weight>0)
        {
            float utility_per_weight=(float)supplies[i].second/supplies[i].first;
            total_utility+=utility_per_weight*remaining_weight;
            remaining_weight=0;
        }
    }

    cout<<total_utility<<endl;
}
