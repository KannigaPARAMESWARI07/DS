#include <stdio.h>
// Function to calculate maximum profit with multiple transactions
int getMaximumTotalProfit(int prices[], int numberOfDays) {
    int totalProfit = 0;
    for (int currentDay = 1; currentDay < numberOfDays; currentDay++) {
        int todayPrice = prices[currentDay - 1];
        int nextDayPrice = prices[currentDay];

        if (nextDayPrice > todayPrice) {
            totalProfit += nextDayPrice - todayPrice;
        }
    }
    return totalProfit;
}
int main() {
    int stockPrices[100], numberOfDays;
    // Input number of days
    printf("Enter number of days: ");
    scanf("%d", &numberOfDays);
    // Input stock prices
    printf("Enter stock prices for each day:\n");
    for (int dayIndex = 0; dayIndex < numberOfDays; dayIndex++) {
        scanf("%d", &stockPrices[dayIndex]);
    }
    // Calculate and display the maximum total profit
    int profit = getMaximumTotalProfit(stockPrices, numberOfDays);
    printf("Maximum Total Profit: %d\n", profit);
    return 0;
}
