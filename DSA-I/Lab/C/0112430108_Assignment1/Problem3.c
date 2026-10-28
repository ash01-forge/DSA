#include <stdio.h>
int searchInsert(int a[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
int main() {
    int n, target;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    int a[100];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target value: ");
    scanf("%d", &target);

    int pos = searchInsert(a, n, target);
    printf("Found at index: %d", pos);

    return 0;
}