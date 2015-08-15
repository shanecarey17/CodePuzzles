#import <stdio.h>
#import <stdlib.h>

/*
 Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  All the children sit in a line, and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies.
*/

int main(int argc, char *argv[]) {

	int num = argc - 1;
	int children[num];
	for (int i = 0; i < num; i++) {
		children[i] = atoi(argv[i + 1]);
	}

	// Dynamic programming solution
	int candies[num];

	// Every student gets at least one candy
	for (int i = 0; i < num; i++) {
		candies[i] = 1;
	}

	// Going right, if any student has a higher score than their left neighbor
	// we need to give them one more candy
	for (int i = 1; i < num; i++) {
		if (children[i] > children[i - 1]) {
			candies[i] = candies[i - 1] + 1;
		}
	}

	// Going left, if any student has a higher score than their right neighbor
	// we need to give them an extra piece of candy iff they have less than their neighbor
	for (int i = num - 2; i >= 0; i--) {
		if (children[i] > children[i + 1]) {
			candies[i] = candies[i] > candies[i + 1] + 1 ? candies[i] : candies[i + 1] + 1;
		}
	}

	// Sum up all the candies
	int sum = 0;
	for (int i = 0; i < num; i++) {
		printf("%d ", candies[i]);
		sum += candies[i];
	}
	printf("\n%d\n", sum);

	return 0;
}
