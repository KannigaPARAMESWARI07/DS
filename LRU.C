/*
 * File Name: LRUCache_TurboC.c
 * 
 * Author: Kanniga Parameswari B, Dharshitha M, Abinaya A
 * 
 * Description: LRU Cache using Doubly Linked List and Hash Table (Turbo C compatible)
 */

#include <stdio.h>              // Standard input/output library
#include <conio.h>              // Console input/output for Turbo C (clrscr, getch)
#include <stdlib.h>            // Standard library for malloc and free
#include <string.h>            // String manipulation library

#define MAX_CAPACITY 100       // Maximum cache capacity
#define MAX_KEY_SIZE 50        // Maximum key length
#define MAX_VALUE_SIZE 100     // Maximum value length
#define HASH_SIZE 101          // Size of the hash table (prime number for better distribution)

// Doubly linked list node
typedef struct Node {
    char key[MAX_KEY_SIZE];           // Key string
    char value[MAX_VALUE_SIZE];       // Value string
    struct Node* prev;                // Pointer to previous node
    struct Node* next;                // Pointer to next node
} Node;

// Hash Table Entry
typedef struct HashEntry {
    char key[MAX_KEY_SIZE];           // Key string
    Node* node;                       // Pointer to corresponding node in DLL
    struct HashEntry* next;          // Next entry in case of collision (chaining)
} HashEntry;

Node* head = NULL;                    // Head of the doubly linked list (most recently used)
Node* tail = NULL;                    // Tail of the doubly linked list (least recently used)
int currentSize = 0;                  // Current size of the cache
int capacity = 0;                     // Maximum size of the cache (user input)

HashEntry* hashTable[HASH_SIZE];      // Hash table array

// Hash function
unsigned int getHashIndex(const char* keyStr) {
    unsigned int hash = 0;                     // Initialize hash value
    int charIndex;                             // Index for character iteration
    for (charIndex = 0; keyStr[charIndex]; charIndex++) {
        hash = (hash + keyStr[charIndex]) % HASH_SIZE;  // Simple hash by summing ASCII values
    }
    return hash;                               // Return final hash index
}

// Search key in hash table
Node* searchHash(const char* searchKey) {
    unsigned int index = getHashIndex(searchKey);     // Get hash index
    HashEntry* entry = hashTable[index];              // Get linked list at index

    while (entry != NULL) {                           // Traverse chain at index
        if (strcmp(entry->key, searchKey) == 0) {     // If key matches
            return entry->node;                       // Return the corresponding node
        }
        entry = entry->next;                          // Move to next entry
    }
    return NULL;                                      // Not found
}

// Insert into hash table
void insertIntoHash(const char* newKey, Node* newNode) {
    unsigned int index = getHashIndex(newKey);        // Get hash index
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));  // Allocate new entry
    strcpy(entry->key, newKey);                       // Copy key
    entry->node = newNode;                            // Link node
    entry->next = hashTable[index];                   // Insert at head (chaining)
    hashTable[index] = entry;                         // Update table
}

// Delete from hash table
void deleteFromHash(const char* deleteKey) {
    unsigned int index = getHashIndex(deleteKey);     // Get hash index
    HashEntry* entry = hashTable[index];              // Get entry at index
    HashEntry* prevEntry = NULL;                      // Track previous for deletion

    while (entry != NULL) {                           // Traverse linked list
        if (strcmp(entry->key, deleteKey) == 0) {     // Key found
            if (prevEntry == NULL) {
                hashTable[index] = entry->next;       // Remove from head
            } else {
                prevEntry->next = entry->next;        // Bypass current
            }
            free(entry);                              // Free memory
            return;
        }
        prevEntry = entry;                            // Move prev pointer
        entry = entry->next;                          // Move to next
    }
}

// Move node to front of DLL
void moveToFront(Node* node) {
    if (node == head)                                 // Already at front
        return;

    if (node->prev != NULL)                           // Unlink from current position
        node->prev->next = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    if (node == tail)                                 // Update tail if needed
        tail = node->prev;

    node->prev = NULL;                                // Move to front
    node->next = head;

    if (head != NULL)
        head->prev = node;

    head = node;                                      // Update head

    if (tail == NULL)                                 // If only one node
        tail = head;
}

// Remove least recently used (tail)
void removeLRU() {
    if (tail == NULL)                                 // Nothing to remove
        return;

    deleteFromHash(tail->key);                        // Remove from hash

    Node* temp = tail;                                // Store current tail
    if (tail->prev != NULL)
        tail->prev->next = NULL;                      // Unlink from DLL

    tail = tail->prev;                                // Update tail

    if (tail == NULL)
        head = NULL;                                  // List becomes empty

    free(temp);                                       // Free memory
    currentSize--;                                    // Decrease size
}

// Put key-value
void put(const char* putKey, const char* putValue) {
    Node* existingNode = searchHash(putKey);          // Check if key exists
    if (existingNode != NULL) {
        strcpy(existingNode->value, putValue);        // Update value
        moveToFront(existingNode);                    // Move to front
    } else {
        if (currentSize >= capacity)                 // If cache full
            removeLRU();                             // Remove LRU

        Node* newNode = (Node*)malloc(sizeof(Node));  // Create new node
        strcpy(newNode->key, putKey);                // Set key
        strcpy(newNode->value, putValue);            // Set value
        newNode->prev = NULL;
        newNode->next = head;                         // Insert at front

        if (head != NULL)
            head->prev = newNode;

        head = newNode;                               // Update head

        if (tail == NULL)
            tail = newNode;                           // If list was empty

        insertIntoHash(putKey, newNode);              // Add to hash
        currentSize++;                                // Increase size
    }
}

// Get key
void get(const char* getKey) {
    Node* node = searchHash(getKey);                  // Search in hash
    if (node != NULL) {
        printf("Value for key '%s': %s\n", getKey, node->value);  // Print value
        moveToFront(node);                            // Move to front
    } else {
        printf("Key '%s' not found.\n", getKey);             // Not found
    }
}

// Print all
void printCache() {
    Node* tempNode = head;                            // Start from head
    printf("Cache content (MRU -> LRU):\n");
    while (tempNode != NULL) {                        // Traverse list
        printf("[%s: %s] ", tempNode->key, tempNode->value);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void main() {
    char command[10];                                 // User command
    char inputKey[MAX_KEY_SIZE];                      // Input key
    char inputValue[MAX_VALUE_SIZE];                  // Input value

    clrscr();                                         // Clear screen (Turbo C)

    printf("Enter cache capacity: ");
    scanf("%d", &capacity);                           // Read capacity

    while (1) {
        printf("\nEnter operation (put/get/exit): ");
        scanf("%s", command);                         // Read command

        if (strcmp(command, "put") == 0) {
            printf("Enter key: ");
            scanf("%s", inputKey);                    // Read key
            printf("Enter value: ");
            scanf("%s", inputValue);                  // Read value
            put(inputKey, inputValue);                // Insert in cache
            printCache();
        } else if (strcmp(command, "get") == 0) {
            printf("Enter key: ");
            scanf("%s", inputKey);                    // Read key
            get(inputKey);                            // Get from cache
            printCache();
        } else if (strcmp(command, "exit") == 0) {
            break;                                    // Exit loop
        } else {
            printf("Invalid command.\n");             // Invalid input
        }
    }

    getch();                                          // Wait for keypress (Turbo C)
}
