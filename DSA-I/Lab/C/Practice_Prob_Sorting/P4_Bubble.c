#include <stdio.h>
int Absolute(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}
void BubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (Absolute(arr[j]) > Absolute(arr[j + 1]))
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
    int i, n, arr[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, n);
    printf("\nThe Sorted Array in Ascending Order: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}