#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,c;
vector<pair<int,int>>items;


bool custom_sort(pair<int,int>a,pair<int,int>b)
{
    float ratio_a=(float)a.second/a.first;
    float ratio_b=(float)b.second/b.first;


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
        int w,profit;
        cin>>w>>profit;
        items.push_back(make_pair(w,profit));
    }
    cin>>c;

    float remaining_weight;
    cin>>remaining_weight;


    sort(items.begin(),items.end(),custom_sort);

    float total_profit=0;

    for(int i=0;i<n;i++)
    {
        if(items[i].first<=remaining_weight)
        {
            total_profit+=items[i].second;
            remaining_weight-=items[i].first;
        }
        else if(remaining_weight>0)
        {
            /// Only the required fraction of this item is taken
            float ratio=(float)items[i].second/items[i].first;
            total_profit+=(ratio*remaining_weight)-c;
            remaining_weight=0;
        }
    }

    cout<<total_profit<<endl;
}
