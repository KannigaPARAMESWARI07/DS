#include <stdio.h>

int findLargestCommonElement(int firstArray[], int sizeFirst, int secondArray[], int sizeSecond) {
    int indexFirst = 0;
    int indexSecond = 0;
    int largestCommon = -1; // Assume no common initially

    while (indexFirst < sizeFirst && indexSecond < sizeSecond) {
        if (firstArray[indexFirst] == secondArray[indexSecond]) {
            largestCommon = firstArray[indexFirst]; // Update latest common
            indexFirst++;
            indexSecond++;
        }
        else if (firstArray[indexFirst] < secondArray[indexSecond]) {
            indexFirst++;
        }
        else {
            indexSecond++;
        }
    }

    return largestCommon; // -1 means no common element
}

int main() {
    int sizeFirst, sizeSecond;

    // Input sizes
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &sizeFirst);
    int firstArray[sizeFirst];

    printf("Enter %d sorted elements for the first array:\n", sizeFirst);
    for (int index = 0; index < sizeFirst; index++) {
        scanf("%d", &firstArray[index]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &sizeSecond);
    int secondArray[sizeSecond];

    printf("Enter %d sorted elements for the second array:\n", sizeSecond);
    for (int index = 0; index < sizeSecond; index++) {
        scanf("%d", &secondArray[index]);
    }

    int result = findLargestCommonElement(firstArray, sizeFirst, secondArray, sizeSecond);

    if (result != -1)
        printf("The largest common element is: %d\n", result);
    else
        printf("No common elements found.\n");

    return 0;
}
