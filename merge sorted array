#include <stdio.h>

void merge(int firstArray[], int sizeFirst, int secondArray[], int sizeSecond, int mergedArray[]) {
    int indexFirst = 0, indexSecond = 0, indexMerged = 0;

    while (indexFirst < sizeFirst && indexSecond < sizeSecond) {
        if (firstArray[indexFirst] < secondArray[indexSecond]) {
            mergedArray[indexMerged++] = firstArray[indexFirst++];
        } else {
            mergedArray[indexMerged++] = secondArray[indexSecond++];
        }
    }

    while (indexFirst < sizeFirst) {
        mergedArray[indexMerged++] = firstArray[indexFirst++];
    }

    while (indexSecond < sizeSecond) {
        mergedArray[indexMerged++] = secondArray[indexSecond++];
    }
}

int main() {
    int sizeFirst, sizeSecond;

    printf("Enter size of first array: ");
    scanf("%d", &sizeFirst);
    int firstArray[sizeFirst];
    printf("Enter %d elements of first sorted array:\n", sizeFirst);
    for (int index = 0; index < sizeFirst; index++) {
        scanf("%d", &firstArray[index]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &sizeSecond);
    int secondArray[sizeSecond];
    printf("Enter %d elements of second sorted array:\n", sizeSecond);
    for (int index = 0; index < sizeSecond; index++) {
        scanf("%d", &secondArray[index]);
    }

    int mergedSize = sizeFirst + sizeSecond;
    int mergedArray[mergedSize];

    merge(firstArray, sizeFirst, secondArray, sizeSecond, mergedArray);

    printf("Total elements in merged array: %d\n", mergedSize);
    printf("Merged array values: ");
    for (int index = 0; index < mergedSize; index++) {
        printf("%d ", mergedArray[index]);
    }
    printf("\n");

    return 0;
}
