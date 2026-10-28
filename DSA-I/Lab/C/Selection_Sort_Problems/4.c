#include <stdio.h>
int Absolute(int x)
{
    if (x < 0)
    {
        return -x;
    }
    else
        return x;
}
void Selection(int arr[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (Absolute(arr[j]) < Absolute(arr[min]))
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int i, n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Selection(arr, n);
    printf("\nThe sorted array are:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}