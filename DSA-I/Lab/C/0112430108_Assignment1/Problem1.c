#include <stdio.h>

int stringLength(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
int compareStrings(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0') return 0;
    if (a[i] == '\0') return -1;
    return 1;
}
void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char a[100][100];
    char temp[100];

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int len1 = stringLength(a[j]);
            int len2 = stringLength(a[j + 1]);

            if (len1 > len2 || 
               (len1 == len2 && compareStrings(a[j], a[j + 1]) > 0)) {

                copyString(temp, a[j]);
                copyString(a[j], a[j + 1]);
                copyString(a[j + 1], temp);
            }
        }
    }

    printf("Sorted output:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", a[i]);

    return 0;
}