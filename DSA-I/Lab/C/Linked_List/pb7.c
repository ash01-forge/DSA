#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int i, x, n;
    struct node *head = NULL, *temp, *newNode;
    struct node *prev = NULL, *curr, *next;
    printf("Enter the size of the node: ");
    scanf("%d", &n);
    printf("Enter the data of the nodes:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newNode = (struct node*)malloc(sizeof(struct node));
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
    curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    return 0;
}