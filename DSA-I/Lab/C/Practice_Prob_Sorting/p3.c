#include <stdio.h>
void Sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int i, j, n, minDif, arr[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the Array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Sort(arr, n);
    minDif = arr[1] - arr[0];
    for (j = 1; j < n; j++)
    {
        int diff = arr[j] - arr[j - 1];
        if (diff < minDif)
        {
            minDif = diff;
        }
    }
    printf("The Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\nThe Smallest Difference of Elements: %d", minDif);
}