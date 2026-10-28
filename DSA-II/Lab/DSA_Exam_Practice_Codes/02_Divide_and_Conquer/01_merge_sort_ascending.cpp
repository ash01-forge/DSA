#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v;

/// MAIN CODE: Merge Sort in ascending order
void merge_sort(int start,int _end)
{
    /// Base cases: a one-element or two-element array is easy to sort
    if(_end-start==1)
    {
        if(v[start]>v[_end])
            swap(v[start],v[_end]);
        return;
    }
    else if(start==_end)
        return;

    int mid=(start+_end)/2;
    merge_sort(start,mid);
    merge_sort(mid+1,_end);

    vector<int>left_array,right_array;

    for(int i=start;i<=mid;i++)
        left_array.push_back(v[i]);

    for(int i=mid+1;i<=_end;i++)
        right_array.push_back(v[i]);

    int i=0,j=0;
    vector<int>new_array;

    while(i<left_array.size() && j<right_array.size())
    {
        if(left_array[i]<right_array[j])
            new_array.push_back(left_array[i++]);
        else
            new_array.push_back(right_array[j++]);
    }

    while(i<left_array.size())
        new_array.push_back(left_array[i++]);

    while(j<right_array.size())
        new_array.push_back(right_array[j++]);

    int p=0;
    for(int k=start;k<=_end;k++)
        v[k]=new_array[p++];
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

    merge_sort(0,n-1);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}
