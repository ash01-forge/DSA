#include <stdio.h>
void BubbleSort(int arr[], int n)
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
    int arr[100], n, k, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of Array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the Kth value: ");
    scanf("%d", &k);
    BubbleSort(arr, n);
    printf("Kth smallest value: %d ", arr[k - 1]);
}