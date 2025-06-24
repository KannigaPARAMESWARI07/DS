#include <stdio.h>
int findCommonMeetingSlot(int personOne[][2], int sizeOne,
                          int personTwo[][2], int sizeTwo,
                          int requiredDuration, int result[2]) {
        int indexOne = 0, indexTwo = 0;
    while (indexOne < sizeOne && indexTwo < sizeTwo) {
        int startTime = (personOne[indexOne][0] > personTwo[indexTwo][0])
                        ? personOne[indexOne][0] : personTwo[indexTwo][0];
        int endTime = (personOne[indexOne][1] < personTwo[indexTwo][1])
                      ? personOne[indexOne][1] : personTwo[indexTwo][1];
        if (endTime - startTime >= requiredDuration) {
            result[0] = startTime;
            result[1] = startTime + requiredDuration;
            return 1;  // Found a valid time slot
        }
        if (personOne[indexOne][1] < personTwo[indexTwo][1]) {
            indexOne++;
        } else {
            indexTwo++;
        }
    }
    return 0;  // No valid slot found
}
int main() {
    int personOne[100][2], personTwo[100][2];
    int sizeOne, sizeTwo;
    int meetingDuration;
    int result[2];
    // Input slots for Person One
    printf("Enter number of time slots for Person One: ");
    scanf("%d", &sizeOne);
    printf("Enter time slots for Person One (start end):\n");
    for (int i = 0; i < sizeOne; i++) {
        scanf("%d %d", &personOne[i][0], &personOne[i][1]);
    }
    // Input slots for Person Two
    printf("Enter number of time slots for Person Two: ");
    scanf("%d", &sizeTwo);
    printf("Enter time slots for Person Two (start end):\n");
    for (int i = 0; i < sizeTwo; i++) {
        scanf("%d %d", &personTwo[i][0], &personTwo[i][1]);
    }
    // Input meeting duration
    printf("Enter required meeting duration: ");
    scanf("%d", &meetingDuration);
    // Find and print the earliest common slot
    if (findCommonMeetingSlot(personOne, sizeOne, personTwo, sizeTwo, meetingDuration, result)) {
        printf("Earliest common meeting slot: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No common slot available.\n");
    }
  return 0;
}
