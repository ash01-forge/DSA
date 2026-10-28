#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n;
vector<int>v;

/// PDF PROBLEM 3: Find maximum and second maximum together
pair<int,int>second_maximum(int start,int _end)
{
    if(start==_end)
    {
        /// A one-element part has no second maximum yet
        return make_pair(v[start],INT_MIN);
    }

    if(_end-start==1)
    {
        if(v[start]>v[_end])
            return make_pair(v[start],v[_end]);
        else
            return make_pair(v[_end],v[start]);
    }

    int mid=(start+_end)/2;
    pair<int,int>left_answer=second_maximum(start,mid);
    pair<int,int>right_answer=second_maximum(mid+1,_end);

    vector<int>possible_values;
    possible_values.push_back(left_answer.first);
    possible_values.push_back(left_answer.second);
    possible_values.push_back(right_answer.first);
    possible_values.push_back(right_answer.second);

    sort(possible_values.begin(),possible_values.end());

    /// The last two positions contain maximum and second maximum
    return make_pair(possible_values[3],possible_values[2]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    /// n must be at least 2
    pair<int,int>answer=second_maximum(0,n-1);
    cout<<answer.second<<endl;
}
