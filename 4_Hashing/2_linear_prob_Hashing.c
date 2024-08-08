#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Htable {
    int key;
    int isOccupied; // 0 if the slot is empty, 1 if it contains an element, -1 if it previously contained an element but was deleted
} Hash_t;

Hash_t* Htable[TABLE_SIZE];

void initHtable() 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        Htable[i] = (Hash_t*)malloc(sizeof(Hash_t));
        Htable[i]->key = 0;      // Initialize key to 0
        Htable[i]->isOccupied = 0;  // Mark entry as empty
    }
}

int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

void insert() 
{
    int key;
    printf("Enter the key to insert: ");
    scanf("%d", &key);
    int index = hashFunction(key);   // Compute the index using the hash function

     for (int i = 0; i < TABLE_SIZE; i++) 
     {
        int new = (index + i) % TABLE_SIZE;  // Compute the new index
        if (Htable[new]->isOccupied == 0 || Htable[new]->isOccupied == -1)  // Check if the slot is empty or previously delete
        {
            Htable[new]->key = key;  // Insert the key
            Htable[new]->isOccupied = 1;  // Mark the slot as occupied
            printf("Key %d inserted at index %d\n", key, new);
            return; 
        }
    }
    printf("Hash table is full, cannot insert key %d\n", key);
}

void delete() 
{
    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int new = (index + i) % TABLE_SIZE;
        if (Htable[new]->isOccupied == 1 && Htable[new]->key == key)  //check if key found
        {
            Htable[new]->isOccupied = -1;    // Mark the slot as previously occupied but now deleted
            printf("Key %d deleted from index %d\n", key, new);
            return;
        }
    }
    printf("Key %d not found in the hash table\n", key);
}

void search() 
{
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int new = (index + i) % TABLE_SIZE;
        if (Htable[new]->isOccupied == 1 && Htable[new]->key == key)  //check if key found
        {
            printf("Key %d found at index %d\n", key, new);
            return;
        }
    }
    printf("Key %d not found in the hash table\n", key);
}

void display() 
{
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        if (Htable[i]->isOccupied == 1)  // check the solt is occupied if yes then print key otherwise print '-'
            printf("Index %d: %d\n", i, Htable[i]->key);
        else 
            printf("Index %d: -\n", i); // ~ represents an empty slot
        
    }
}

int main() 
{
    initHtable();
    int choice;

    while (1) 
    {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                for (int i = 0; i < TABLE_SIZE; i++) {
                    free(Htable[i]);
                }
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
