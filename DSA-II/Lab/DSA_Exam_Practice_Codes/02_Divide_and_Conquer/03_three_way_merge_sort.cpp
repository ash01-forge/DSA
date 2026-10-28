#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n;
vector<int>v;

/// PDF VARIATION 1(b): Divide the array into three sections
void merge_sort(int start,int _end)
{
    if(start>=_end)
        return;

    int first_mid=start+(_end-start)/3;
    int second_mid=start+2*(_end-start)/3;

    merge_sort(start,first_mid);
    merge_sort(first_mid+1,second_mid);
    merge_sort(second_mid+1,_end);

    vector<int>first_array,second_array,third_array,new_array;

    for(int i=start;i<=first_mid;i++)
        first_array.push_back(v[i]);

    for(int i=first_mid+1;i<=second_mid;i++)
        second_array.push_back(v[i]);

    for(int i=second_mid+1;i<=_end;i++)
        third_array.push_back(v[i]);

    int i=0,j=0,k=0;

    /// In every step, take the smallest front value of the three arrays
    while(i<first_array.size() || j<second_array.size() || k<third_array.size())
    {
        int smallest=INT_MAX;
        int selected_array=0;

        if(i<first_array.size() && first_array[i]<=smallest)
        {
            smallest=first_array[i];
            selected_array=1;
        }

        if(j<second_array.size() && second_array[j]<=smallest)
        {
            smallest=second_array[j];
            selected_array=2;
        }

        if(k<third_array.size() && third_array[k]<=smallest)
        {
            smallest=third_array[k];
            selected_array=3;
        }

        new_array.push_back(smallest);

        if(selected_array==1)
            i++;
        else if(selected_array==2)
            j++;
        else
            k++;
    }

    int p=0;
    for(int index=start;index<=_end;index++)
        v[index]=new_array[p++];
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
