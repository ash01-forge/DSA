#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v;

/// PDF VARIATION 1(a): Merge Sort in descending order
void merge_sort(int start,int _end)
{
    if(_end-start==1)
    {
        /// Reversed comparison keeps the larger value first
        if(v[start]<v[_end])
            swap(v[start],v[_end]);
        return;
    }
    else if(start==_end)
        return;

    int mid=(start+_end)/2;
    merge_sort(start,mid);
    merge_sort(mid+1,_end);

    vector<int>left_array,right_array,new_array;

    for(int i=start;i<=mid;i++)
        left_array.push_back(v[i]);

    for(int i=mid+1;i<=_end;i++)
        right_array.push_back(v[i]);

    int i=0,j=0;

    while(i<left_array.size() && j<right_array.size())
    {
        /// Reversed comparison is the main descending-order change
        if(left_array[i]>right_array[j])
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
