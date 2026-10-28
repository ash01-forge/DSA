#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


bool custom_sort(pair<int,int>a, pair<int,int>b)
{
    if(a.first+a.second>b.first+b.second)
        return true;
    else
        return false;
}




int main()
{
    /// take an array as input using vector and return the sum of the array============
    /*
    vector<int> v;
    int n; // array size
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        // v[i]
        int temp;
        cin>>temp;
        v.push_back(temp);

    }
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    while(!v.empty()) // v.empty() --> is the vector empty
    {
        v.pop_back();
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    */
    //==========================
    /*
    string s;
    cin>>s;
    cout<<s.length()<<endl;
    cout<<s.substr(3,2)<<endl;
    cout<<s[3]<<endl;
    */
    /// sort an array of pairs based on the first element
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;
        pair<int,int> p=make_pair(a,b);
        //cout<<p.first<<p.second;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),custom_sort);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    // reverse(v.begin(),v.end());
















}


