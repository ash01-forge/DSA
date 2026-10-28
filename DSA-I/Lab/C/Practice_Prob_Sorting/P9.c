#include <stdio.h>
int main()
{
    int i, j, n, n1, n2, temp, arr[200], b[100], c[100];
    printf("Enter the value of n1: ");
    scanf("%d", &n1);
    printf("\nEnter the Array elements for n1: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("Enter the value of n2: ");
    scanf("%d", &n2);
    printf("\nEnter the Array elements for n2: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &c[i]);
    }
    for (i = 0; i < n1; i++)
    {
        arr[i] = b[i];
    }

    for (i = 0; i < n2; i++)
    {
        arr[n1 + i] = c[i];
    }
    n = n1 + n2;
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
    printf("Merged and Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    return 0;
}