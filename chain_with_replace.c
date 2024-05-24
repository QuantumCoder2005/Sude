//chain_with_replace
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for chaining
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hash Table structure
typedef struct HashTable {
    int* table;
    Node** chains;
    int size;
    int collisions;
} HashTable;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the hash table
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->table = (int*)malloc(size * sizeof(int));
    hashTable->chains = (Node**)malloc(size * sizeof(Node*));
    hashTable->size = size;
    hashTable->collisions = 0;

    for (int i = 0; i < size; i++) {
        hashTable->table[i] = -1; // -1 indicates an empty slot
        hashTable->chains[i] = NULL;
    }

    return hashTable;
}

// Hash function
int hashFunction(int key, int size) {
    return key % size;
}

// Function to insert data into the hash table
void insert(HashTable* hashTable, int data) {
    int index = hashFunction(data, hashTable->size);
    int originalIndex = index;

    // Check if the slot is empty
    if (hashTable->table[index] == -1) {
        hashTable->table[index] = data;
    } else {
        // If the slot is not empty, linear probing
        hashTable->collisions++;
        while (hashTable->table[index] != -1) {
            index = (index + 1) % hashTable->size;
            if (index == originalIndex) {
                printf("Hash table is full, cannot insert %d\n", data);
                return;
            }
        }
        hashTable->table[index] = data;

        // Insert the original element to the chain of the new position
        Node* newNode = createNode(hashTable->table[originalIndex]);
        newNode->next = hashTable->chains[originalIndex];
        hashTable->chains[originalIndex] = newNode;

        // Place the new data in the original position
        hashTable->table[originalIndex] = data;
    }
}

// Function to display the hash table
void display(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("%d: %d", i, hashTable->table[i]);
        Node* chain = hashTable->chains[i];
        while (chain) {
            printf(" -> %d", chain->data);
            chain = chain->next;
        }
        printf("\n");
    }
    printf("Number of collisions: %d\n", hashTable->collisions);
}

int main() {
    HashTable* hashTable = createHashTable(TABLE_SIZE);

    int choice, data;
    while (1) {
        printf("\nMenu:\n1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(hashTable, data);
            break;
        case 2:
            display(hashTable);
            break;
        case 3:
            free(hashTable->table);
            for (int i = 0; i < TABLE_SIZE; i++) {
                Node* chain = hashTable->chains[i];
                while (chain) {
                    Node* temp = chain;
                    chain = chain->next;
                    free(temp);
                }
            }
            free(hashTable->chains);
            free(hashTable);
            return 0;
        default:
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

