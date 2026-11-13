
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} n;

n *create(int v);
void display(n *);

int main()
{
    n *root;
    root = create(40);
    root->left = create(50);
    root->left->left = create(20);
    root->left->left->left = create(10);
    root->right = create(15);
    root->right->right = create(25);
    root->right->right->right = create(35);
    display(root);
    return 0;
}

n *create(int v)
{
    n *new;
    new = (n *)malloc(sizeof(n));
    new->data = v;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void display(n *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    display(root->left);
    display(root->right);
}
