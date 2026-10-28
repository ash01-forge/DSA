#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} int main()
{
    int n, x, i, target, count = 0;
    struct node *head = NULL, *temp, *newNode;
    printf("Enter the value of node: ");
    scanf("%d", &n);
    printf("\nEnter the data of the nodes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            count++;
            temp = temp->next;
        }
        else
            temp = temp->next;
    }
    printf("Occurences: %d", count);
    return 0;
}