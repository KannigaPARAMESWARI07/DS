/*
 * File Name: LRUCache.c
 * 
 * Author: Kanniga Parameswari B, Dharshitha M, Abinaya A
 * 
 * Description: LRU Cache implementation using Doubly Linked List and Hash Map.
 *              Allows string keys and values. Takes user input for cache capacity and operations.
 */

#include <stdio.h>               // Standard I/O functions
#include <stdlib.h>              // For malloc, free
#include <string.h>              // For string handling

#define MAX_CAPACITY 100         // Maximum possible cache capacity
#define MAX_STRING 100           // Maximum string length

// Structure for doubly linked list node
typedef struct Node {
    char key[MAX_STRING];        // Key as string
    char value[MAX_STRING];      // Value as string
    struct Node* prev;           // Pointer to previous node
    struct Node* next;           // Pointer to next node
} Node;

Node* head = NULL;               // Head of the doubly linked list
Node* tail = NULL;               // Tail of the doubly linked list

// Hash map structure for fast access using keys
typedef struct {
    char key[MAX_STRING];        // Key
    Node* node;                  // Pointer to node in DLL
} HashEntry;

HashEntry* hashMap[MAX_CAPACITY]; // Hash table for storing key-node pairs
int capacity = 0;                // User-defined cache capacity
int currentSize = 0;             // Current number of entries in cache

// Function to create a new node
Node* createNode(char* key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));     // Allocate memory
    strcpy(newNode->key, key);                       // Set key
    strcpy(newNode->value, value);                   // Set value
    newNode->prev = NULL;                            // Initialize prev to NULL
    newNode->next = NULL;                            // Initialize next to NULL
    return newNode;                                  // Return new node
}

// Function to hash a key (simple sum of chars)
int hashFunction(char* key) {
    int hash = 0;                                     // Initialize hash value
    for (int i = 0; key[i]; i++) {                    // Iterate over characters
        hash += key[i];                               // Add ASCII value of each character
    }
    return hash % MAX_CAPACITY;                       // Return hash index
}

// Function to remove a node from doubly linked list
void removeNode(Node* node) {
    if (!node) return;                                // Return if node is NULL

    if (node->prev) node->prev->next = node->next;    // Update previous node's next
    else head = node->next;                           // If node is head, move head

    if (node->next) node->next->prev = node->prev;    // Update next node's prev
    else tail = node->prev;                           // If node is tail, move tail
}

// Function to insert a node at front of DLL
void insertAtFront(Node* node) {
    node->next = head;                                // Set node's next to current head
    node->prev = NULL;                                // Set node's prev to NULL
    if (head) head->prev = node;                      // Update head's prev if exists
    head = node;                                      // Update head to new node
    if (!tail) tail = head;                           // If tail is NULL, point to head
}

// Function to update hash map
void updateHashMap(char* key, Node* node) {
    int hashIndex = hashFunction(key);                // Get hash index
    while (hashMap[hashIndex] != NULL && strcmp(hashMap[hashIndex]->key, key) != 0) {
        hashIndex = (hashIndex + 1) % MAX_CAPACITY;   // Linear probing
    }
    if (hashMap[hashIndex] == NULL) {
        hashMap[hashIndex] = (HashEntry*)malloc(sizeof(HashEntry));  // Allocate entry
    }
    strcpy(hashMap[hashIndex]->key, key);             // Set key
    hashMap[hashIndex]->node = node;                  // Set node pointer
}

// Function to get node from hash map
Node* getFromHashMap(char* key) {
    int hashIndex = hashFunction(key);                // Get hash index
    int originalIndex = hashIndex;                    // Store original index
    while (hashMap[hashIndex] != NULL) {
        if (strcmp(hashMap[hashIndex]->key, key) == 0) {
            return hashMap[hashIndex]->node;          // Key match, return node
        }
        hashIndex = (hashIndex + 1) % MAX_CAPACITY;   // Linear probing
        if (hashIndex == originalIndex) break;        // Full loop, exit
    }
    return NULL;                                      // Not found
}

// Function to perform GET operation
void get(char* key) {
    Node* node = getFromHashMap(key);                 // Retrieve node
    if (node == NULL) {
        printf("Key '%s' not found in cache\n", key); // Key not found
    } else {
        removeNode(node);                             // Remove from current position
        insertAtFront(node);                          // Move to front
        printf("Value for key '%s': %s\n", key, node->value); // Print value
    }
}

// Function to perform PUT operation
void put(char* key, char* value) {
    Node* existing = getFromHashMap(key);             // Check if key already exists

    if (existing != NULL) {                           // Key exists
        strcpy(existing->value, value);               // Update value
        removeNode(existing);                         // Remove from list
        insertAtFront(existing);                      // Move to front
    } else {
        if (currentSize == capacity) {                // If cache full
            int tailIndex = hashFunction(tail->key);  // Get tail hash
            while (hashMap[tailIndex] != NULL && strcmp(hashMap[tailIndex]->key, tail->key) != 0) {
                tailIndex = (tailIndex + 1) % MAX_CAPACITY;
            }
            free(hashMap[tailIndex]);                 // Free hash entry
            hashMap[tailIndex] = NULL;                // Nullify
            removeNode(tail);                         // Remove from DLL
            currentSize--;                            // Decrement size
        }

        Node* newNode = createNode(key, value);       // Create new node
        insertAtFront(newNode);                       // Add to DLL
        updateHashMap(key, newNode);                  // Add to hash map
        currentSize++;                                // Increment size
    }
}

// Function to display current cache content
void displayCache() {
    Node* temp = head;                                // Start from head
    printf("Current Cache State (Most recent to least):\n");
    while (temp != NULL) {
        printf("Key: %s, Value: %s\n", temp->key, temp->value); // Print key-value
        temp = temp->next;                            // Move to next node
    }
}

int main() {
    printf("Enter cache capacity: ");
    scanf("%d", &capacity);                           // Get cache size from user

    int choice;
    char key[MAX_STRING], value[MAX_STRING];

    while (1) {
        printf("\n1. Put\n2. Get\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);                         // Get user choice

        if (choice == 1) {
            printf("Enter key: ");
            scanf("%s", key);                         // Input key
            printf("Enter value: ");
            scanf("%s", value);                       // Input value
            put(key, value);                          // Call put
        } else if (choice == 2) {
            printf("Enter key: ");
            scanf("%s", key);                         // Input key
            get(key);                                 // Call get
        } else if (choice == 3) {
            displayCache();                           // Show cache
        } else if (choice == 4) {
            break;                                    // Exit loop
        } else {
            printf("Invalid choice\n");               // Invalid input
        }
    }

    return 0;                                         // End program
}
