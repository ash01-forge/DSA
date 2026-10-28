#include <stdio.h>

int searchInsert(int a[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
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
    printf("Insert index: %d", pos);

    return 0;
}