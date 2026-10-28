#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

/// CLASS EXAMPLE: binary_search, lower_bound, upper_bound,
/// accumulate and max_element
int main()
{
    int n;
    cin>>n;

    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    /// These three functions need a sorted vector
    sort(v.begin(),v.end());

    int x;
    cin>>x;

    bool found=binary_search(v.begin(),v.end(),x);
    cout<<"binary_search: "<<found<<endl;

    auto first_position=lower_bound(v.begin(),v.end(),x);
    auto after_last_position=upper_bound(v.begin(),v.end(),x);

    cout<<"element_count: "<<after_last_position-first_position<<endl;
    cout<<"sum: "<<accumulate(v.begin(),v.end(),0)<<endl;
    cout<<"maximum: "<<*max_element(v.begin(),v.end())<<endl;
}
