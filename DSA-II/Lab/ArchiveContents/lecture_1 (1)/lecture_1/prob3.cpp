#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    vector<int> v = {2,3,6,9,11,12,12,12,15,16};
    //v.begin() = returns the pointer to the first element
    //v.end() = returns the pointer to the last element
    bool b=binary_search(v.begin(),v.end(),15); // true if found, otherwise false
    cout<<"binary_search:"<<b<<endl;


    ///lower_bound=returns a pointer of the number x closest to 12 such that x>=12
    auto it=lower_bound(v.begin(),v.end(),12); /// first 12
    cout<<"lower_bound:"<<*it<<endl;


    ///upper_bound=returns a pointer of the number x closest to 12 such that x>12
    auto it2=upper_bound(v.begin(),v.end(),12); /// 15
    cout<<"upper_bound:"<<*it2<<endl;

    cout<<"element count:"<<it2-it<<endl; /// returns the count of 12


    int it3=accumulate(v.begin(),v.end(),0);
    cout<<"Sum:"<<it3<<endl;

    auto it4=max_element(v.begin(),v.end());
    cout<<"max element:"<<*it4<<endl;










}

