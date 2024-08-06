#include<stdio.h>
#include<stdlib.h>
 
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data);
struct node preOrder(struct node *root);
struct node inOrder(struct node *root);
struct node postOrder(struct node *root);

/*
             1
            /  \
           2    3
         /  \    \
        4   5     6
*/
void main()
{
    struct node *root = NULL;
    root = createnode(1);
    struct node *l = createnode(2);
    struct node *l1 = createnode(4);
    struct node *l2 = createnode(5);
    struct node *r = createnode(3);
    struct node *r1 = createnode(6);

    // Linking the root node with left and right children
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = l2;
    r->right = r1;

    printf("PreOrder list is: ");
    preOrder(root);
    printf("\nInOrder list is: ");
    inOrder(root);
    printf("\nPostOrder list is: ");
    postOrder(root);

}

struct node *createnode(int data)
{
    struct node *newN = NULL;
    newN =(struct node*) malloc(sizeof(struct node));
    newN->data = data;
    newN->left = NULL;
    newN->right= NULL;
    return newN;   
}

struct node preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct node inOrder(struct node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
struct node postOrder(struct node *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}