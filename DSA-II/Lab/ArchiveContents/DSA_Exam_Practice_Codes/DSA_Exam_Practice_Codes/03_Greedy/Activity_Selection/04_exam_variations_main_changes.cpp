/*
    EXTRA EXAM VARIATIONS - ONLY MAIN CHANGES

    1. Print every selected activity:
       Inside the selection if-block add:
       cout<<works[i].first<<" "<<works[i].second<<endl;

    2. Immediate next work is NOT allowed:
       Change:
       if(works[i].first>=current_finish_time)
       To:
       if(works[i].first>current_finish_time)

    3. If two works end together, put the later-starting one first:
       bool custom_sort(pair<int,int>a,pair<int,int>b)
       {
           if(a.second==b.second)
               return a.first>b.first;
           return a.second<b.second;
       }
*/

int main()
{
    return 0;
}
