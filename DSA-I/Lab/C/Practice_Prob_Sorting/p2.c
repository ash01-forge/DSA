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
    int i, arr[100], n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the Array elements: ");
    for (i = 0; i < n; i++)
    { 
        scanf("%d", &arr[i]);
    }
    Sort(arr, n);
    float median;

    if (n % 2 == 1)
    {
        median = (arr[n / 2]);
    }
    else
    {
        median = ((arr[(n / 2) - 1] + arr[n / 2]) / 2.0);
    }
    printf("The sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\nThe Median: %.1f", median);
}