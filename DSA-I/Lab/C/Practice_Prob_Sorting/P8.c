#include <stdio.h>
int main()
{
    int i, j, n, temp, arr[100], freq[100] = {0};
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the Array Elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (freq[arr[j]] < freq[arr[j + 1]] || (freq[arr[j]] == freq[arr[j + 1]] && arr[j] > arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    return 0;
}