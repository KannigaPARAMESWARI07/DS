#include <stdio.h>
int main() {
    int firstArray[100], secondArray[100];
    int sizeFirst, sizeSecond;

    // Input size and elements of first array
    printf("Enter size of first array: ");
    scanf("%d", &sizeFirst);
    printf("Enter elements of first array:\n");
    for (int i = 0; i < sizeFirst; i++) {
        scanf("%d", &firstArray[i]);
    }

    // Input size and elements of second array
    printf("Enter size of second array: ");
    scanf("%d", &sizeSecond);
    printf("Enter elements of second array:\n");
    for (int i = 0; i < sizeSecond; i++) {
        scanf("%d", &secondArray[i]);
    }

    // Print common elements
    printf("Common elements: ");
    for (int i = 0; i < sizeFirst; i++) {
        for (int j = 0; j < sizeSecond; j++) {
            if (firstArray[i] == secondArray[j]) {
                printf("%d ", firstArray[i]);
                break; // Avoid printing duplicates
            }
        }
    }

    return 0;
}
