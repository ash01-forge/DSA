/*
    EXTRA EXAM VARIATIONS - ONLY MAIN CHANGES

    1. Sort integers in descending order:
       sort(v.begin(),v.end(),greater<int>());

    2. Count how many times x occurs in a sorted vector:
       auto first=lower_bound(v.begin(),v.end(),x);
       auto last=upper_bound(v.begin(),v.end(),x);
       int count=last-first;

    3. Find the first index of x:
       auto it=lower_bound(v.begin(),v.end(),x);
       if(it!=v.end() && *it==x)
           cout<<it-v.begin()<<endl;
       else
           cout<<-1<<endl;

    4. Second maximum where duplicate maximum is allowed:
       sort(v.begin(),v.end());
       cout<<v[v.size()-2]<<endl;

    5. Custom sort pairs by second value in ascending order:
       bool custom_sort(pair<int,int>a,pair<int,int>b)
       {
           if(a.second<b.second)
               return true;
           else
               return false;
       }
*/

int main()
{
    return 0;
}
