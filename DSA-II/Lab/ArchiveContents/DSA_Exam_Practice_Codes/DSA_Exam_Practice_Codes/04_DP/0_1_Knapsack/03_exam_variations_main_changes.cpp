/*
    EXTRA EXAM VARIATIONS - ONLY MAIN CHANGES

    1. Values are profit and weights are cost:
       Only rename arrays. The recurrence stays exactly the same.

    2. A student can study a chapter only once:
       weight[] = required time
       value[]  = obtained marks
       capacity = available study time

       The same taken/not_taken code works.

    3. Plain recursion without memoization:
       Remove:
       if(dp[current_item][rem_capacity]!=-1)
           return dp[current_item][rem_capacity];

       Remove:
       dp[current_item][rem_capacity]=answer;

    4. Input capacity is given in hours but weights are minutes:
       int available_minutes=capacity*60;
       cout<<solve(0,available_minutes)<<endl;

    Main exam idea:
       0/1 means both taken and not_taken calls use current_item+1.
*/

int main()
{
    return 0;
}
