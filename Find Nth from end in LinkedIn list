#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int inputValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = inputValue;
    newNode->next = NULL;
    return newNode;
}
void appendNode(struct Node** headReference, int inputValue) {
    struct Node* newNode = createNode(inputValue);
    if (*headReference == NULL) {
        *headReference = newNode;
        return;
    }
    struct Node* currentNode = *headReference;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}
int getNodeValueFromEnd(struct Node* headNode, int positionFromEnd) {
    struct Node* leadPointer = headNode;
    struct Node* followPointer = headNode;
    int stepsMoved = 0;
    while (stepsMoved < positionFromEnd) {
        if (leadPointer == NULL) return -1;
        leadPointer = leadPointer->next;
        stepsMoved++;
    }
    while (leadPointer != NULL) {
        leadPointer = leadPointer->next;
        followPointer = followPointer->next;
    }
    return (followPointer != NULL) ? followPointer->data : -1;
}
int main() {
    struct Node* headNode = NULL;
    int totalNodeCount, currentIndex, currentValue, targetPosition;
    printf("Enter total number of nodes: ");
    scanf("%d", &totalNodeCount);
    for (currentIndex = 1; currentIndex <= totalNodeCount; currentIndex++) {
        printf("Enter value for node %d: ", currentIndex);
        scanf("%d", &currentValue);
        appendNode(&headNode, currentValue);
    }
    printf("Enter position from end to retrieve: ");
    scanf("%d", &targetPosition);
    int nodeValue = getNodeValueFromEnd(headNode, targetPosition);
    printf("Value at %d-th node from the end: %d\n", targetPosition, nodeValue);
    return 0;
}
