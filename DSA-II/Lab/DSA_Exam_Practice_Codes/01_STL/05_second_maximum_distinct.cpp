#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// EXAM PROBLEM: Find the second distinct maximum using STL
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

    sort(v.begin(),v.end());

    int maximum=v[n-1];
    int second_maximum=maximum;

    /// Move left until a value smaller than maximum is found
    for(int i=n-2;i>=0;i--)
    {
        if(v[i]<maximum)
        {
            second_maximum=v[i];
            break;
        }
    }

    if(second_maximum==maximum)
        cout<<"No distinct second maximum"<<endl;
    else
        cout<<second_maximum<<endl;
}
