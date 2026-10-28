#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i, n, x;
    struct node *head = NULL, *temp, *newNode;
    printf("Enter the size of nodes:");
    scanf("%d", &n);
    printf("Enter the node data:");
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

    while (head != NULL && head->data % 2 == 0)
    {
        head = head->next;
    }
    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data % 2 == 0)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    return 0;
}