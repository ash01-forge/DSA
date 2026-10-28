#include <stdio.h>
int main()
{
    int i, n, j, k = 0, l = 0, arr[100], odd[100], even[100], temp;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\nEnter the Array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even[k] = arr[i];
            k++;
        }
        else
        {
            odd[l] = arr[i];
            l++;
        }
    }
    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (even[j] > even[j + 1])
            {
                temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < l - 1; i++)
    {
        for (j = 0; j < l - i - 1; j++)
        {
            if (odd[j] < odd[j + 1])
            {
                temp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = temp;
            }
        }
    }
    k = 0;
    l = 0;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = even[k];
            k++;
        }
        else
        {
            arr[i] = odd[l];
            l++;
        }
    }
    printf("Output: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}