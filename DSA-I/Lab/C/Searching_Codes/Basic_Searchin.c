#include <stdio.h>
int Binary_Searching(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int i, n, key;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the target: ");
    scanf("%d", &key);
    int res = Binary_Searching(arr, n, key);
    if (res == -1)
    {
        printf("\nElement not found");
    }
    else
        printf("\nElement found at index= %d", res);
    return 0;
}