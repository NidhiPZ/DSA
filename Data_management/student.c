#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HelpMenu  "-----:choices are:-----\n"           \
                  "1. Enter the student details\n"      \
                  "2. Display Students\n"               \
                  "3. Delete Student by ID\n"           \
                  "4. Find by name\n"                   \
                  "5. Edit Student detail\n"            \
                  "6. Exit\n"                           \
                  "Enter '0' to see menu again\n "   

// Define the structure for a student node in the linked list
typedef struct Student
{
    int id;               
    char name[20];        
    int age;              
    char address[50];     
    struct Student *next; // Pointer to the next node in the linked list
}Student_t;

void Add_student(Student_t **head);
void Delete_student(Student_t **head);
void Display_studentData(Student_t *node);
void Find_Student(Student_t *head);
void Edit_Student(Student_t *head);


Student_t *head = NULL;  // Head pointer of the linked list

int main() 
{   
    int choice;

    printf("%s", HelpMenu); 

    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 0:
                // Re-print the menu
                printf("%s", HelpMenu);
                break;

            case 1:
                Add_student(&head);
                break;

            case 2:
                Display_studentData(head);
                break;

            case 3:
                Delete_student(&head);
                break;

            case 4:
                Find_Student(head);
                break;

            case 5:
                Edit_Student(head);
                break;

            case 6:
                exit(1);
                
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
/*
    *brief this function adds the  new student data
    *param head 
    @return none
*/
void Add_student(Student_t **head)
{
    Student_t *new_stu = (Student_t*)malloc(sizeof(Student_t));
    Student_t *last = *head;  // Pointer to traverse the list

    printf("Enter Id: ");
    scanf("%d", &new_stu->id);

    // Check if the ID already exists
    Student_t *temp = *head;
    while (temp != NULL)
    {
        if (temp->id == new_stu->id)
        {
            printf("Error: Id already exists. Please use a unique ID.\n");
            free(new_stu);
            return;
        }
        temp = temp->next;
    }
    getchar();  // Clear newline character from buffer
    printf("Enter Name: ");
    gets(new_stu->name);
    printf("Enter Age: ");
    scanf("%d", &new_stu->age);
    getchar();  // Clear newline character from buffer
    printf("Enter Address: ");
    gets(new_stu->address);

    new_stu->next = NULL; // New student will be the last node in the list

    // If the list is empty, the new student is the head
    if (*head == NULL)
    {
        *head = new_stu;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL)
        last = last->next;

    last->next = new_stu;  // Add the new student to the end of the list
}

void Display_studentData(Student_t *node)
{
    if (node == NULL)      
    {
        printf("No students found.\n");
        return;
    }

    while (node != NULL)  //traverse and print each student's details
    {
        printf("\nID: %d \t Name: %s \t Age: %d \t Address: %s", node->id, node->name, node->age, node->address);
        node = node->next; // Move to the next student
    }
    printf("\n");
}

void Delete_student(Student_t **head)
{
    int id;
    Student_t *temp = *head;
    Student_t *prev = NULL;

    printf("Enter ID of student to delete: ");
    scanf("%d", &id);

    // If head node itself holds the ID to be deleted
    if (temp != NULL && temp->id == id)
    {
        *head = temp->next;  // Update head to the next node
        free(temp);  // Free the memory of the deleted node
        printf("Student with ID %d deleted.\n", id);
        return;
    }

    // Search for the node to be deleted, keep track of the previous node
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the ID was not found in the list
    if (temp == NULL)
    {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;  // Unlink the node from the linked list
    free(temp);  // Free memory
    printf("Student with ID %d deleted.\n", id);
}

void Find_Student(Student_t *head)
{
    char name[20];
    printf("Enter Name of student to find: ");
    scanf("%s", name);

    Student_t *temp = head;
    int found = 0;

    // Traverse the list to find the student by name
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            // If a match is found, print the student's details
            printf("\nID: %d \t Name: %s \t Age: %d \t Address: %s\n", temp->id, temp->name, temp->age, temp->address);
            found = 1;
            break;
        }
        temp = temp->next; // Move to the next student
    }

    if (!found)
    {
        printf("Student with name %s not found.\n", name);
    }
}

// function to edit student details by ID
void Edit_Student(Student_t *head)
{
    int id;
    printf("Enter ID of the student to edit: ");
    scanf("%d", &id);

    Student_t *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            int choice;
            printf("What do you want to edit?\n1. Name\n2. Age\n3. Address\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter new Name: ");
                    scanf("%s", temp->name);
                    break;
                case 2:
                    printf("Enter new Age: ");
                    scanf("%d", &temp->age);
                    break;
                case 3:
                    getchar();  // Clear the newline character from the buffer
                    printf("Enter new Address: ");
                    gets(temp->address);
                    break;
                default:
                    printf("Invalid choice\n");
                    return;
            }
            printf("Student details updated successfully.\n");
            printf("ID: %d \t Name: %s \t Age: %d \t Address: %s\n", temp->id, temp->name, temp->age, temp->address);

            return;
        }
        temp = temp->next;
    }

    printf("Student with ID %d not found.\n", id);
}