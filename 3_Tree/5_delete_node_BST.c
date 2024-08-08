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
struct node *inorderPredecessor(struct node *root);
struct node *delete(struct node *root, int val);



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
    printf("\nenter the node to delete: ");
    scanf("%d",&num);
    root =  delete(root,num);

    printf("InOrder list is: ");
    inOrder(root);
    
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

struct node *delete(struct node *root, int val)
{
    struct node *ipre;   // Pointer to store the in-order predecessor
    if(root == NULL)
        return NULL;
        
    if(root->left == NULL && root->right == NULL)
    {   
        // If the node is a leaf node 
        free(root);  // Free the memory of the node
        return NULL;  // Return NULL to the parent node
    }


    //search for node to delete
    if(val < root->data)
        root->left=delete(root->left, val);  // Recur on left subtree
    else if(val > root->data)
        root->right=delete(root->right, val);  // Recur on right subtree

    //delete when the node found
    else
    {
        ipre = inorderPredecessor(root);  // Find the in-order predecessor
        root->data = ipre->data;   // Copy the in-order predecessor's data to this node
        root->left = delete(root->left, ipre->data);  // Delete the in-order predecessor
    }
    return root;
}
struct node *inorderPredecessor(struct node *root)
{ 
    root = root-> left;   // Move to the left subtree
    while(root->right !=NULL)
    {
        root=root->right;    // Find the rightmost node in the left subtree
    }
    return root;   // Return the in-order predecessor
}


