#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
void print_list(struct node *head);
void insert_end(struct node **head, int data);
void rotate_list(struct node **head, int n);

int main()
{
    struct node *head = NULL; // Initialize head pointer to NULL
    int data, n, i;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input data for nodes and create the list
    for (i = 1; i <= n; i++)
     {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insert_end(&head, data);
    }

    // Print the doubly linked list
    printf("\nThe doubly linked list is:\n");
    print_list(head);
    // Input the number of nodes to rotate
    printf("\nEnter the number of nodes to rotate by: ");
    scanf("%d", &n);

    // Rotate the doubly linked list by n nodes
    rotate_list(&head, n);

    // Print the rotated doubly linked list
    printf("The rotated doubly linked list is:\n");
    print_list(head);
}
// Function to insert a node at the end of the doubly linked list
void insert_end(struct node **head, int data)
 {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *head;

    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) 
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    // Traverse to the end of the list
    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }

    // Update the next of the last node and prev of the new node
    ptr->next = new_node;
    new_node->prev = ptr;
}

// Function to print the doubly linked list
void print_list(struct node *head)
 {
    struct node *ptr;

    while (head != NULL) 
    {
        printf("%d ", head->data);
        ptr = head;
        head = head->next;
    }
  
}
// Function to rotate the doubly linked list by n nodes
void rotate_list(struct node **head, int n)
{
    struct node *ptr = *head;
    int count = 1;

    // Traverse to the nth node
    while (count < n && ptr != NULL) 
    {
        ptr = ptr->next;
        count++;
    }

    struct node *nth_node = ptr;

    // Traverse to the end of the list
    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }

    // Update the next of the last node to the head and the prev of the head to the last node
    ptr->next = *head;
    (*head)->prev = ptr;

    // Update the head to the node next to nth_node and set the prev of the new head to NULL
    *head = nth_node->next;
    (*head)->prev = NULL;

    // Set the next of the nth_node to NULL
    nth_node->next = NULL;
}