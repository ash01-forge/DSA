#include <stdio.h>

int main()
{
    int n, i, j, temp;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int start[100], finish[100], duration[100];

    // Input start and finish times
    printf("Enter Start and Finish times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &start[i], &finish[i]);
        duration[i] = finish[i] - start[i]; // calculate duration
    }

    // Bubble sort based on duration
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (duration[j] > duration[j + 1])
            {
                // swap duration
                temp = duration[j];
                duration[j] = duration[j + 1];
                duration[j + 1] = temp;

                // swap start
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                // swap finish
                temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;
            }
        }
    }

    // Output
    printf("Sorted Tasks based on duration:\n");
    for (i = 0; i < n; i++)
    {
        printf("(%d, %d) ", start[i], finish[i]);
    }

    return 0;
}