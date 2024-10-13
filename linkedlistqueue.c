#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void Push(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("QUEUE EMPTY\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void pop()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("QUEUE EMPTY\n");
    }
    else
    {
        front = front->next;
        free(temp);
    }
}
void peek()
{

    printf("%d", front->data);
}

int main()
{
    Push(5);
    Push(0);
    Push(-3);
    display();
    pop();
    display();
    return 0;
}
