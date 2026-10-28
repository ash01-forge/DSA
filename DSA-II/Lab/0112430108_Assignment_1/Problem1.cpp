#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> D;

int max_sum_subarray(int start, int _end)
{
    if (start == _end)
        return D[start];

    int mid = (start + _end) / 2;

    int left_maximum =
        max_sum_subarray(start, mid);

    int right_maximum =
        max_sum_subarray(mid + 1, _end);

    int left_boundary = -100000000;
    int current_sum = 0;

    for (int i = mid; i >= start; i--)
    {
        current_sum += D[i];
        left_boundary = max(left_boundary, current_sum);
    }

    int right_boundary = -100000000;
    current_sum = 0;

    for (int i = mid + 1; i <= _end; i++)
    {
        current_sum += D[i];
        right_boundary = max(right_boundary, current_sum);
    }

    int crossing_sum =
        left_boundary + right_boundary;

    return max(crossing_sum,
               max(left_maximum, right_maximum));
}

int min_sum_subarray(int start, int _end)
{
    if (start == _end)
        return D[start];

    int mid = (start + _end) / 2;

    int left_minimum =
        min_sum_subarray(start, mid);

    int right_minimum =
        min_sum_subarray(mid + 1, _end);

    int left_boundary = 100000000;
    int current_sum = 0;

    for (int i = mid; i >= start; i--)
    {
        current_sum += D[i];
        left_boundary = min(left_boundary, current_sum);
    }

    int right_boundary = 100000000;
    current_sum = 0;

    for (int i = mid + 1; i <= _end; i++)
    {
        current_sum += D[i];
        right_boundary = min(right_boundary, current_sum);
    }

    int crossing_sum =
        left_boundary + right_boundary;

    return min(crossing_sum,
               min(left_minimum, right_minimum));
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int daily_pnl;
        cin >> daily_pnl;
        D.push_back(daily_pnl);
    }

    int Max_Profit_Streak =
        max_sum_subarray(0, N - 1);

    int minimum_sum =
        min_sum_subarray(0, N - 1);

    int Risk_Reserve = 0;

    if (minimum_sum < 0)
        Risk_Reserve = -minimum_sum;

    cout << Max_Profit_Streak << endl;
    cout << Risk_Reserve << endl;
}