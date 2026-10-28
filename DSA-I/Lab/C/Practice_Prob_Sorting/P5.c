#include <stdio.h>
#include <string.h>
int main()
{
    int n, i, j;
    char a[100][100];
    char temp[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the Strings: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strlen(a[j]) > strlen(a[j + 1]))
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }
    printf("\nSorted Strings by Length: ");
    for (i = 0; i < n; i++)
    {
        printf(" %s", a[i]);
    }
}