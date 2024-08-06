#include<stdio.h>
#include<stdlib.h>
 
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data);
struct node inOrder(struct node *root);
void insert(struct node *root, int key);
struct node preOrder(struct node *root);

/*
             6
            /  \
           4    8
         /  \    \
        2    5    10
*/
void main()
{
    struct node *root = NULL;
    root = createnode(6);
    struct node *l = createnode(4);
    struct node *l1 = createnode(2);
    struct node *l2 = createnode(5);
    struct node *r = createnode(8);
    struct node *r1 = createnode(10);

    // Linking the root node with left and right children
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = l2;
    r->right = r1;

    printf("InOrder list is: ");
    inOrder(root);

    int num;
    printf("\nenter the node to insert: ");
    scanf("%d",&num);
    insert(root,num);
    printf("InOrder list is: ");
    inOrder(root);
    printf("\n");
    printf("PreOrder list is: ");
    preOrder(root);
   
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

struct node inOrder(struct node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}


void insert(struct node *root, int key)
{
   struct node *prev = NULL;
   while(root!=NULL)
   {
       prev = root;
       if(key==root->data)
       {
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data)
           root = root->left;
       else
           root = root->right;
       
   }
   struct node* new = createnode(key);
   if(key<prev->data)
       prev->left = new;
   
   else
       prev->right = new;
   
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
