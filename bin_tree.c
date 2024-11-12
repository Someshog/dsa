#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter the left child of %d, ", x);
    newnode->left = create();
    printf("Enter the right child of %d, ", x);
    newnode->right = create();
    return newnode;
}
int traverse_inorder(struct node *root)
{ // left root right
    if (root == 0)
    {
        return 0;
    }
    traverse_inorder(root->left);
    printf("%d ", root->data);
    traverse_inorder(root->right);
}
int traverse_preorder(struct node *root)
{ // root left right
    if (root == 0)
    {
        return 0;
    }
    printf("%d ", root->data);
    traverse_preorder(root->left);
    traverse_preorder(root->right);
}
int traverse_postorder(struct node *root)
{ // left right root
    if (root == 0)
    {
        return 0;
    }
    traverse_postorder(root->left);
    traverse_postorder(root->right);
    printf("%d ", root->data);
}
void insert(struct node *root, int val)
{
    struct node *temp = NULL;
    while (root != NULL)
    {
        temp = root;
        if (val == root->data)
        {
            return;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if (val < temp->data)
    {
        temp->left = newnode;
    }
    else
    {
        temp->right = newnode;
    }
}

void main()
{
    struct node *root;
    root = 0;
    root = create();
    insert(root, 9);
    printf("Inorder Traversing: ");
    traverse_inorder(root);
    printf("\nPreorder Traversing: ");
    traverse_preorder(root);
    printf("\nPostorder Traversing: ");
    traverse_postorder(root);
}