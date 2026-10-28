#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>>items;

/// PRACTICE PROBLEM 3: The Master Chef's Pantry
/// pair<weight,flavor_score>
bool custom_sort(pair<int,int>a,pair<int,int>b)
{
    float ratio_a=(float)a.second/a.first;
    float ratio_b=(float)b.second/b.first;

    /// Higher value per unit weight must come first
    if(ratio_a>ratio_b)
        return true;
    else
        return false;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int weight,flavor_score;
        cin>>weight>>flavor_score;
        items.push_back(make_pair(weight,flavor_score));
    }

    float remaining_weight;
    cin>>remaining_weight;

    sort(items.begin(),items.end(),custom_sort);

    float total_flavor_score=0;

    for(int i=0;i<n;i++)
    {
        if(items[i].first<=remaining_weight)
        {
            total_flavor_score+=items[i].second;
            remaining_weight-=items[i].first;
        }
        else if(remaining_weight>0)
        {
            /// Only the required fraction of this item is taken
            float ratio=(float)items[i].second/items[i].first;
            total_flavor_score+=ratio*remaining_weight;
            remaining_weight=0;
        }
    }

    cout<<total_flavor_score<<endl;
}
