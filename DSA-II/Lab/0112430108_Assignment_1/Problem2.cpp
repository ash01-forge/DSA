#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> D;

void _merge_sort(int start, int _end)
{
    if (_end - start == 1)
    {
        if (D[start] < D[_end])
            swap(D[start], D[_end]);

        return;
    }
    else if (start == _end)
        return;

    int mid = (start + _end) / 2;

    _merge_sort(start, mid);
    _merge_sort(mid + 1, _end);

    vector<int> left_array;
    vector<int> right_array;

    for (int i = start; i <= mid; i++)
        left_array.push_back(D[i]);

    for (int i = mid + 1; i <= _end; i++)
        right_array.push_back(D[i]);

    int i = 0;
    int j = 0;

    vector<int> merged_array;

    while (i < left_array.size() &&
           j < right_array.size())
    {
        if (left_array[i] > right_array[j])
        {
            merged_array.push_back(left_array[i]);
            i++;
        }
        else
        {
            merged_array.push_back(right_array[j]);
            j++;
        }
    }

    while (i < left_array.size())
    {
        merged_array.push_back(left_array[i]);
        i++;
    }

    while (j < right_array.size())
    {
        merged_array.push_back(right_array[j]);
        j++;
    }

    int position = 0;

    for (int i = start; i <= _end; i++)
    {
        D[i] = merged_array[position];
        position++;
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        D.push_back(value);
    }

    _merge_sort(0, N - 1);

    for (int i = 0; i < N; i++)
        cout << D[i] << " ";
}