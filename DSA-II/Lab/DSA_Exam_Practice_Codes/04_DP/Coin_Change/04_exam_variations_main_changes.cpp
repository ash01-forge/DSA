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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
DSA MID EXAM — BLIND-SPOT CODES

Topic 1: 0/1 Knapsack — Bottom-Up DP
Topic 2: Minimum Coin Change — Bottom-Up DP
Topic 3: Coin Change Unordered Ways — Bottom-Up DP

Choice:
1 = 0/1 Knapsack
2 = Minimum Coin Change
3 = Coin Change Unordered Ways
========================================================
*/

// ======================================================
// TOPIC 1: 0/1 KNAPSACK — BOTTOM-UP DYNAMIC PROGRAMMING
// ======================================================

void zero_one_knapsack()
{
    /*
    Input format:

    n
    weight value
    weight value
    ...
    capacity

    Example:
    3
    2 3
    3 4
    4 5
    5

    Output:
    7
    */

    int n;
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    int capacity;
    cin >> capacity;

    /*
    dp[i][w] means:

    Maximum value using the first i items
    when available capacity is w.
    */

    vector<vector<int>> dp(
        n + 1,
        vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            // Option 1: Do not take the current item
            int not_taken = dp[i - 1][w];

            // Initially, current item is not taken
            int taken = 0;

            /*
            Current item index is i-1 because
            vector indexing starts from 0.
            */

            if (weight[i - 1] <= w)
            {
                taken = value[i - 1] + dp[i - 1][w - weight[i - 1]];
            }

            // Store the better answer
            dp[i][w] = max(taken, not_taken);
        }
    }

    cout << dp[n][capacity] << endl;
}

// ======================================================
// TOPIC 2: MINIMUM COIN CHANGE — BOTTOM-UP DP
// ======================================================

void minimum_coin_change()
{
    /*
    Input format:

    coin_type
    coin values
    required change

    Example:
    3
    1 3 4
    6

    Output:
    2

    Explanation:
    6 = 3 + 3

    Every coin may be used unlimited times.
    */

    int coin_type;
    cin >> coin_type;

    vector<int> coin_value(coin_type);

    for (int i = 0; i < coin_type; i++)
    {
        cin >> coin_value[i];
    }

    int change;
    cin >> change;

    const int INF = 100000000;

    /*
    dp[amount] means:

    Minimum number of coins required
    to create the given amount.
    */

    vector<int> dp(change + 1, INF);

    // Zero coins are needed to create amount zero
    dp[0] = 0;

    for (int amount = 1; amount <= change; amount++)
    {
        for (int i = 0; i < coin_type; i++)
        {
            int coin = coin_value[i];

            if (coin <= amount)
            {
                int remaining_amount = amount - coin;

                /*
                Use this coin only when the remaining
                amount was possible to create.
                */

                if (dp[remaining_amount] != INF)
                {
                    dp[amount] = min(
                        dp[amount],
                        1 + dp[remaining_amount]);
                }
            }
        }
    }

    // Exact change is impossible
    if (dp[change] == INF)
        cout << -1 << endl;
    else
        cout << dp[change] << endl;
}

// ======================================================
// TOPIC 3: COIN CHANGE — NUMBER OF UNORDERED WAYS
// ======================================================

void unordered_coin_change_ways()
{
    /*
    Input format:

    coin_type
    coin values
    required change

    Example:
    3
    1 2 3
    4

    Output:
    4

    Combinations:
    1 + 1 + 1 + 1
    1 + 1 + 2
    1 + 3
    2 + 2

    1+3 and 3+1 are considered the same combination.
    Every coin may be used unlimited times.
    */

    int coin_type;
    cin >> coin_type;

    vector<int> coin_value(coin_type);

    for (int i = 0; i < coin_type; i++)
    {
        cin >> coin_value[i];
    }

    int change;
    cin >> change;

    /*
    dp[amount] means:

    Number of unordered combinations
    that can create the given amount.
    */

    vector<long long> dp(change + 1, 0);

    /*
    There is one way to create amount zero:
    select no coins.
    */

    dp[0] = 1;

    /*
    IMPORTANT EXAM RULE:

    Coin loop must be outside.
    Amount loop must be inside.

    This prevents different orders from
    being counted as different combinations.
    */

    for (int i = 0; i < coin_type; i++)
    {
        int coin = coin_value[i];

        for (int amount = coin; amount <= change; amount++)
        {
            dp[amount] += dp[amount - coin];
        }
    }

    cout << dp[change] << endl;
}

// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    /*
    Enter:

    1 for 0/1 Knapsack
    2 for Minimum Coin Change
    3 for Unordered Coin Change Ways
    */

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        zero_one_knapsack();
    }
    else if (choice == 2)
    {
        minimum_coin_change();
    }
    else if (choice == 3)
    {
        unordered_coin_change_ways();
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
