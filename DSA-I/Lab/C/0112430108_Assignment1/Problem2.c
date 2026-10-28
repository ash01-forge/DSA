#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[100];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int even[100], odd[100];
    int e = 0, o = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even[e++] = a[i];
        else
            odd[o++] = a[i];
    }

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (even[j] > even[j + 1]) {
                int t = even[j];
                even[j] = even[j + 1];
                even[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < o - 1; i++) {
        for (int j = 0; j < o - i - 1; j++) {
            if (odd[j] < odd[j + 1]) {
                int t = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = t;
            }
        }
    }

    e = 0; o = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            a[i] = even[e++];
        else
            a[i] = odd[o++];
    }

    printf("Output:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}