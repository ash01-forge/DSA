#include <stdio.h>
int Absolute(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}
void SelectionSort(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
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
    int i, n, arr[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    SelectionSort(arr, n);
    printf("\nThe Sorted Array in Ascending Order: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}