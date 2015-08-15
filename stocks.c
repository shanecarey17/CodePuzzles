#include <stdio.h>
#include <stdlib.h>

/*
 Copyright (c) 2015 Shane Carey

 Maximizes the profit given a series of stock prices
 May buy one stock or sell any number of stock on any given day
 Start with 0 stock
 Input is a series of stock prices
 Output is maximum possible profit
*/

int maxProfit(int *prices, int length) {
	// Keep running track of profit and max price we have encountered
	int profit = 0;
	int maxPrice = 0;

	// Run a backwards loop through the prices (reverse time)
	for (int i = length - 1; i >= 0; i--) {
		// Hold on to the maximum price from the end, this is the highest price going forwards
		if (maxPrice <= prices[i]) {
			maxPrice = prices[i];
		}

		// We calculate profit by subtracting the price of the day from the maxPrice that we will sell the stock at, found above
		profit += maxPrice - prices[i];
	}	
	return profit;
}

int main(int argc, char *argv[]) {
	// Load the prices array
	int prices[argc - 1];
	for (int i = 1; i < argc; i++) {
		prices[i - 1] = atoi(argv[i]);
	}

	// Solve
	int max = maxProfit(prices, argc - 1);
	printf("%d\n", max);
	return 0;
}
