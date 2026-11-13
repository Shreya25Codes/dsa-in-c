#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} n;

n* insert(n *root, int val);
void display(n *root);
int secondHighest(n *root, int *ans);
int commonParent(n *root);
int height(n *root);
int onlyLeft(n *root);

int main()
{
    n *root = NULL;
    int num, val, ch, ans;

    printf("Enter number of nodes: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++)
    {
        printf("Enter data: ");
        scanf("%d", &val);

        root = insert(root, val);
    }

    printf("\nBinary Search Tree: ");
    display(root);

    while(1)
    {
        printf("\n\n----- MENU -----");
        printf("\n1. Find Second Highest Data");
        printf("\n2. Count Nodes Having Common Parent");
        printf("\n3. Find Height of BST");
        printf("\n4. Count Nodes Having Only Left Child");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                if(secondHighest(root, &ans))
                    printf("\nSecond highest data = %d", ans);
                else
                    printf("\nSecond highest node does not exist.");
                break;

            case 2:
                printf("\nNodes having common parent = %d",
                       commonParent(root));
                break;

            case 3:
                printf("\nHeight of BST = %d", height(root));
                break;

            case 4:
                printf("\nNodes having only left child = %d",
                       onlyLeft(root));
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}

n* insert(n *root, int val)
{
    if(root == NULL)
    {
        n *newnode = (n*)malloc(sizeof(n));

        if(newnode == NULL)
        {
            printf("\nMemory allocation failed!");
            return NULL;
        }
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if(val < root->data)
        root->left = insert(root->left, val);

    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void display(n *root)
{
    if(root == NULL)
        return;

    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int secondHighest(n *root, int *ans)
{
    n *curr = root;
    n *parent = NULL;
    n *temp;

    if(root == NULL)
        return 0;

    while(curr->right != NULL)
    {
        parent = curr;
        curr = curr->right;
    }

    if(curr->left != NULL)
    {
        temp = curr->left;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        *ans = temp->data;
        return 1;
    }
    if(parent != NULL)
    {
        *ans = parent->data;
        return 1;
    }
    return 0;
}

int commonParent(n *root)
{
    if(root == NULL)
        return 0;

    int count = 0;

    if(root->left != NULL && root->right != NULL)
        count = 2;

    count = count + commonParent(root->left);
    count = count + commonParent(root->right);
    return count;
}

int height(n *root)
{
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

int onlyLeft(n *root)
{
    if(root == NULL)
        return 0;

    int count = 0;

    if(root->left != NULL && root->right == NULL)
        count = 1;

    count = count + onlyLeft(root->left);
    count = count + onlyLeft(root->right);
    return count;
}
