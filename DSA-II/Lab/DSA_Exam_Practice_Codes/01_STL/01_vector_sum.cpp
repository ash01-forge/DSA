#include<iostream>
#include<vector>
using namespace std;

/// CLASS PROBLEM: Take an array using vector and find its sum
int main()
{
    int n;
    cin>>n;

    vector<int>v;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }

    cout<<sum<<endl;
}
