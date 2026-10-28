#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int size(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
int main()
{
    int n, x, i;
    struct node *head = NULL, *temp, *newNode;
    printf("ENter the number of Nodes: ");
    scanf("%d", &n);
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
    printf("Size of Linked List= %d\n ", size(head));
    return 0;
}