#include <stdio.h>

int removeDuplicates(int sortedArray[], int originalSize, int uniqueArray[]) {
    if (originalSize == 0) return 0;

    int indexUnique = 0;
    uniqueArray[indexUnique++] = sortedArray[0];

    for (int indexCurrent = 1; indexCurrent < originalSize; indexCurrent++) {
        if (sortedArray[indexCurrent] != sortedArray[indexCurrent - 1]) {
            uniqueArray[indexUnique++] = sortedArray[indexCurrent];
        }
    }

    return indexUnique; // New size of array without duplicates
}

int main() {
    int originalSize;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &originalSize);

    int sortedArray[originalSize];
    printf("Enter %d sorted elements:\n", originalSize);
    for (int indexInput = 0; indexInput < originalSize; indexInput++) {
        scanf("%d", &sortedArray[indexInput]);
    }

    int uniqueArray[originalSize];
    int newSize = removeDuplicates(sortedArray, originalSize, uniqueArray);

    printf("Array after removing duplicates (%d elements):\n", newSize);
    for (int indexOutput = 0; indexOutput < newSize; indexOutput++) {
        printf("%d ", uniqueArray[indexOutput]);
    }
    printf("\n");

    return 0;
}
