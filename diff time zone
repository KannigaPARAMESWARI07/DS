#include <stdio.h>
// Define a structure to hold hour and minute
typedef struct {
    int hour;
    int minute;
} Time;

Time adjustTimeByOffset(Time originalTime, int offsetHours, int offsetMinutes) {
    originalTime.minute += offsetMinutes;
    originalTime.hour += offsetHours + originalTime.minute / 60;
    originalTime.minute = (originalTime.minute + 60) % 60;
    originalTime.hour = (originalTime.hour + 24) % 24;
    return originalTime;
}
int main() {
    Time istTime, gmtTime, targetZoneTime;
    float inputIstFloatTime;
    int istToGmtOffsetHours = -5;
    int istToGmtOffsetMinutes = -30;
    int gmtToTargetOffsetHours = -5;
    int gmtToTargetOffsetMinutes = 0;
    printf("Enter IST time (HH.MM): ");
    scanf("%f", &inputIstFloatTime);
    istTime.hour = (int)inputIstFloatTime;
    istTime.minute = (int)((inputIstFloatTime - istTime.hour) * 100 + 0.5);  // Prevent float error
gmtTime = adjustTimeByOffset(istTime, istToGmtOffsetHours, istToGmtOffsetMinutes);
targetZoneTime = adjustTimeByOffset(gmtTime, gmtToTargetOffsetHours, gmtToTargetOffsetMinutes);
    printf("\nIST Time     : %02d:%02d\n", istTime.hour, istTime.minute);
    printf("GMT Time     : %02d:%02d\n", gmtTime.hour, gmtTime.minute);
    printf("Target Time  : %02d:%02d\n", targetZoneTime.hour, targetZoneTime.minute);
return 0;
}
