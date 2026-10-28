#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
int main()
{
    int n, i, x;
    struct node *head = NULL, *temp, *newNode;
    printf("Enter the value of nodes:");
    scanf("%d", &n);
    printf("Enter the data of nodes:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    return 0;
}