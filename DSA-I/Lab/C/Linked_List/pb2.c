#include <Stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int n, i, x, count = 0;
    struct node *head = NULL, *temp, *newNode;
    printf("Enter the size of the node: ");
    scanf("%d", &n);
    printf("\nEnter the Data of the node: ");
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
        count++;
        temp = temp->next;
    }
    temp = head;
    for (i = 0; i < count / 2; i++)
    {
        temp = temp->next;
    }
    printf("Middle= %d", temp->data);
    return 0;
}
