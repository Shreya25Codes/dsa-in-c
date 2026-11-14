#include <Stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} n;

n *create(int v)
{
    n *new = (n *)malloc(sizeof(n));
    new->data = v;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void display(n *root)
{
    n *p;
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

int count(n *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right != NULL)
        return 1;

    return count(root->left) + count(root->right);
}

int main()
{
    n *root;
    root = create(40);
    root->left = create(50);
    root->right = create(30);
    display(root);
    printf("No. of nodes:%d", count(root));
    return 0;
} 
