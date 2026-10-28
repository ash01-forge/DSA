#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int n, i, x, num;
    struct node *head = NULL, *temp, *newNode;
    printf("Enter the value of node:");
    scanf("%d", &n);
    printf("\nEnter the data of nodes:");
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
    printf("Enter the number: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    if (head == NULL || num < head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->data < num)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    temp = head;
    while (temp != NULL)
    {

       printf("%d->", temp->data);
        temp = temp->next;
    }
}