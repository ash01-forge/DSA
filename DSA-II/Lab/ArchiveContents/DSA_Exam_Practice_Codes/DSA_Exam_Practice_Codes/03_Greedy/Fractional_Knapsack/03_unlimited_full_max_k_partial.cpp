#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>>items;

/// FRACTIONAL KNAPSACK VARIATION:
/// Unlimited full items, but no more than K partial items
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
        int weight,value;
        cin>>weight>>value;
        items.push_back(make_pair(weight,value));
    }

    float remaining_weight;
    int K;
    cin>>remaining_weight>>K;

    sort(items.begin(),items.end(),custom_sort);

    float total_value=0;
    int partial_item_count=0;

    for(int i=0;i<n;i++)
    {
        /// while, instead of if, allows unlimited full copies
        while(items[i].first<=remaining_weight)
        {
            total_value+=items[i].second;
            remaining_weight-=items[i].first;
        }

        if(remaining_weight>0 && partial_item_count<K)
        {
            float value_per_weight=(float)items[i].second/items[i].first;
            total_value+=value_per_weight*remaining_weight;

            /// A partial item fills all remaining capacity
            remaining_weight=0;
            partial_item_count++;
        }

        if(remaining_weight==0)
            break;
    }

    cout<<total_value<<endl;
}
