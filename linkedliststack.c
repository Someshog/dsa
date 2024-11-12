#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = x;
    if (top == NULL)
    {
        newnode->next = NULL;
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
int pop()
{
    if (top == NULL)
    {
        printf("EMPTY!");
    }
    else
    {

        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}
void peek()
{
    printf("the top element is: %d", top->data);
}
void display()
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    display();
    push(10);
    display();
    peek();
}