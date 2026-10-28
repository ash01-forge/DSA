/*
    EXTRA EXAM VARIATIONS - ONLY MAIN CHANGES

    1. Print -1 when exact change is impossible:
       int answer=solve(change);
       if(answer>=100000000)
           cout<<-1<<endl;
       else
           cout<<answer<<endl;

    2. Count ordered ways instead of minimum coins:
       Base case:
       if(rem_change==0)
           return 1;

       Starting value:
       long long total_ways=0;

       Inside the loop:
       total_ways+=solve(rem_change-coin_value[i]);

       Do not add 1 and do not use min().

    3. Each coin may be used only once:
       Add current_coin to the state:
       solve(current_coin,rem_change)

       Taken call:
       solve(current_coin+1,rem_change-coin_value[current_coin])

       Not-taken call:
       solve(current_coin+1,rem_change)

    Main exam idea:
       Minimum coin change loops through every coin again,
       so the same coin may be reused unlimited times.
*/

int main()
{
    return 0;
}
