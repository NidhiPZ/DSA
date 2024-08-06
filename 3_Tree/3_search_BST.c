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
int isBST(struct  node* root);
struct node *search(struct node *root, int key);

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
    printf("\n");
    if(isBST(root))
    {
        printf("This is a BST" );
    }
    else
    {
        printf("This is not a BST");
    }
    struct node *p = NULL;
    int num;
    printf("\nenter the node u want to search: ");
    scanf("%d",&num);
    p = search(root,num);
    if(p!=NULL)
    {
        printf("Found: %d", p->data);
    }
    else{
        printf("Element not found");
    }
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

int isBST(struct  node* root)
{
    static struct node *prev = NULL;  // Static variable to keep track of previous node in in-order traversal
    if(root!=NULL)
    {
        if(!isBST(root->left))   // Recursively check the left subtree
        {
            return 0;   //left subtree is not BST, return false
        }
        // Check if current node's data is less than or equal to previous node's data
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root; // Update previous node
        return isBST(root->right);    // Recursively check the right subtree
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *root, int key)
{
    if(root==NULL)
        return NULL;

    if(key == root->data)
        return root;

    else if(key<root->data)
        return search(root->left,key);
    else
        return search(root->right,key);

}