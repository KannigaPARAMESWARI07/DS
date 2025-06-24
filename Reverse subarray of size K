#include <stdio.h>
void reverseGroup(int array[], int start, int end) {
    while (start < end) {
        int temp = array[start];
        array[start++] = array[end];
        array[end--] = temp;
    }
}
int main() {
    int array[100], size, groupSize;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    for (int index = 0; index < size; index++) {
        scanf("%d", &array[index]);
    }
    printf("Enter group size (k): ");
    scanf("%d", &groupSize);
  
    if (groupSize <= 0) {
        printf("Invalid k\n");
        return 0;
    }
   
    for (int start = 0; start < size; start += groupSize) {
        int end = (start + groupSize - 1 < size) ? start + groupSize - 1 : size - 1;
        reverseGroup(array, start, end);
    }
    // Output result
    printf("Output: ");
    for (int index = 0; index < size; index++) {
        printf("%d ", array[index]);
    }
    return 0;
}
