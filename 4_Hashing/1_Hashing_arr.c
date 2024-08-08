//hash table using linear probing to resolve collisions.
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];
int isOccupied[TABLE_SIZE]; // 0 if the slot is empty, 1 if it contains an element, -1 if it previously contained an element but was deleted

void initHashTable() 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hashTable[i] = 0; // Initialize each slot to 0
        isOccupied[i] = 0; // Set each slot as empty
    }
}

int Hashfunc(int key) 
{
    return key % TABLE_SIZE;
}

void insert() 
{
    int key;
    printf("Enter the key to insert: ");
    scanf("%d", &key);
    int index = Hashfunc(key);  // Compute the index using the hash function

    // Linear probing to find an empty slot
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int new= (index + i) % TABLE_SIZE;
        if (isOccupied[new] == 0 || isOccupied[new] == -1)  // Check if the slot is empty or previously deleted
        {
            hashTable[new] = key;  // Insert the key
            isOccupied[new] = 1;   // Mark the slot as occupied
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
    int index = Hashfunc(key);

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int new = (index + i) % TABLE_SIZE;
        if (isOccupied[new] == 1 && hashTable[new] == key)  // Check if the key is found
        {
            isOccupied[new] = -1;  //marked slot as deleted
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
    int index = Hashfunc(key);

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int new = (index + i) % TABLE_SIZE;
        if (isOccupied[new] == 1 && hashTable[new] == key)  //check if key is found
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
        if (isOccupied[i] == 1) 
            printf("Index %d: %d\n", i, hashTable[i]);        
        else 
            printf("Index %d: ~\n", i); // ~ represents an empty slot        
    }
}

int main()
{
    initHashTable();
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
