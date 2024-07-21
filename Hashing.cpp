#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10 // Define the size of the hash table

// Function to compute hash value using Division Remainder Method
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert an element into the hash table using linear probing
void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    // Linear probing for collision resolution
    while (hashTable[index] != -1) {
        index = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Function to search for an element in the hash table
bool search(int hashTable[], int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    // Linear probing to search the element
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return true;
        }
        index = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) {
            return false;
        }
    }

    return false;
}

// Function to display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("Index %d: Empty\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

// Main function to test the hash table operations
int main() {
    int hashTable[TABLE_SIZE];

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    int choice, key;

    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(hashTable, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(hashTable, key)) {
                    printf("%d found in hash table.\n", key);
                } else {
                    printf("%d not found in hash table.\n", key);
                }
                break;
            case 3:
                display(hashTable);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

