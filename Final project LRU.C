/*
* File name: LRU_Cache.c
*
* Author: Kanniga Parameswari B, Dharshitha M, Abinaya A
*
* Description: C program implementing an LRU (Least Recently Used) Cache system using arrays.
*              Supports put, get, and display operations.
*/

#include <stdio.h>             // Includes standard input/output functions
#include <string.h>            // Includes string handling functions (not used here, but safe to include)

#define MAX_CAPACITY 100       // Defines the maximum number of cache entries allowed

// Structure to represent a single cache item
typedef struct {
    int key;                   // The unique key of the cache item
    int value;                 // The value associated with the key
} CacheEntry;

CacheEntry cache[MAX_CAPACITY]; // Array to store cache entries
int currentSize = 0;            // Current number of entries in the cache
int capacity = 0;               // User-defined maximum size for the cache

// Function to move a recently accessed item to the front of the cache (MRU)
void moveToFront(int position) {
    CacheEntry temp = cache[position];         // Temporarily store the selected entry
    for (int index = position; index > 0; index--) {
        cache[index] = cache[index - 1];       // Shift all elements forward
    }
    cache[0] = temp;                           // Place the accessed entry at the front
}

// Function to insert or update a cache entry
void putInCache(int key, int value) {
    int position = -1;                         // Track if the key already exists
    for (int index = 0; index < currentSize; index++) {
        if (cache[index].key == key) {         // If key found in the cache
            position = index;                  // Save its position
            break;                             // Exit loop early
        }
    }

    if (position != -1) {                      // If key exists
        cache[position].value = value;         // Update its value
        moveToFront(position);                 // Move it to the front (MRU)
    } else {
        if (currentSize == capacity) {         // If cache is full
            for (int index = capacity - 1; index > 0; index--) {
                cache[index] = cache[index - 1]; // Make space by shifting items
            }
            cache[0].key = key;                // Add new key at front
            cache[0].value = value;            // Set its value
        } else {                               // If space is available
            for (int index = currentSize; index > 0; index--) {
                cache[index] = cache[index - 1]; // Shift items to insert at front
            }
            cache[0].key = key;                // Set new key at front
            cache[0].value = value;            // Set its value
            currentSize++;                     // Increase the size count
        }
    }
}

// Function to retrieve value by key from the cache
int getFromCache(int key) {
    for (int index = 0; index < currentSize; index++) {
        if (cache[index].key == key) {         // If key is found
            moveToFront(index);                // Move it to front (MRU)
            return cache[0].value;             // Return its value
        }
    }
    return -1;                                 // Key not found, return -1
}

// Function to display the current state of the cache
void displayCache() {
    printf("Current Cache (Most Recently Used to Least): ");
    for (int index = 0; index < currentSize; index++) {
        printf("[%d:%d] ", cache[index].key, cache[index].value); // Show key-value pairs
    }
    printf("\n");                              // Newline after displaying cache
}

// Function to display the user menu options
void printMenu() {
    printf("\nLRU Cache Menu:\n");             // Print menu heading
    printf("1. Put key-value pair\n");         // Option to insert/update cache
    printf("2. Get value by key\n");           // Option to retrieve value
    printf("3. Display cache\n");              // Option to show cache
    printf("4. Exit\n");                       // Option to exit the program
    printf("Choose an option: ");              // Prompt for user input
}

// Main function where program starts
int main() {
    printf("Enter cache capacity: ");          // Ask user for desired cache capacity
    scanf("%d", &capacity);                    // Store the input in 'capacity'

    if (capacity > MAX_CAPACITY) {             // If user input exceeds maximum allowed
        printf("Capacity too large. Max allowed: %d\n", MAX_CAPACITY);
        return 1;                              // Exit with error code
    }

    while (1) {                                // Infinite loop for menu
        printMenu();                           // Show menu
        int choice;
        scanf("%d", &choice);                  // Read user’s menu selection

        if (choice == 1) {                     // Option 1: Put
            int key, value;
            printf("Enter key: ");
            scanf("%d", &key);                 // Read key from user
            printf("Enter value: ");
            scanf("%d", &value);               // Read value
            putInCache(key, value);            // Insert into cache
            printf("Put operation done for key %d with value %d.\n", key, value);
            displayCache();                    // Show updated cache
        }
        else if (choice == 2) {                // Option 2: Get
            int key;
            printf("Enter key: ");
            scanf("%d", &key);                 // Read key to retrieve
            int result = getFromCache(key);    // Search in cache
            if (result == -1)
                printf("Key %d not found in cache.\n", key);  // Not found
            else
                printf("Key %d found with value %d.\n", key, result); // Found
            displayCache();                    // Show current cache
        }
        else if (choice == 3) {                // Option 3: Display
            displayCache();                    // Display cache content
        }
        else if (choice == 4) {                // Option 4: Exit
            break;                             // Exit loop and program
        }
        else {
            printf("Invalid option. Try again.\n"); // Handle wrong input
        }
    }

    return 0;                                  // Exit successfully
}
