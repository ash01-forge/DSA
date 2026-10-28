#include <stdio.h>
int main()
{
    int n, i, j, temp, arr[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\nEnter the Array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (n == 0)
    {
        printf("The Longest Consecutive Number is 0\n");
    }

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
    int longest = 1;
    int current = 1;
    for (i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            current++;
        }

        else if (arr[i] == arr[i - 1])
        {
            continue;
        }
        else
        {
            if (current > longest)
            {
                longest = current;
            }
            current = 1;
        }
        if (current > longest)
        {
            longest = current;
        }
    }
        printf("Longest Consecutive Number: %d", longest);
    
    return 0;
}