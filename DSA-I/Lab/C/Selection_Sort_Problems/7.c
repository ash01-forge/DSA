#include <stdio.h>
void Selection(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main()
{
    int i, n, count = 1;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Selection(arr, n);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == (arr[i + 1] - 1))
        {
            count++;
        }
        else
            break;
    }
    printf("%d", count);
}