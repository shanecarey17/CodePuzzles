#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Print header
	printf(" FR | R1 | R2 | R3 | PTS \n");
	
	// Keep track of index of roll in input
	int idx = 0;
	
	// Running score total
	int score = 0;

	// For each ten frames
	for (int frame = 0; frame < 10; frame++) {
		// Print divider
		printf("----+----+----+----+-----\n");
		
		// Characters for printing score
		char *rollPts[3] = {"", "", ""};

		// Keep track of the points in this frame
		int framePts = 0;

		// Calculate number of rolls possible in this frame
		int rolls = frame == 9 ? 3 : 2;

		// Flags end of the game (if early)
		int endGame = 0;

		// For each roll
		for (int roll = 0; roll < rolls; roll++) {
			if (idx == argc - 1) {
				// If this is the last roll, end the game
				endGame = 1;
				break;
			}

			// Place the roll in the buffer
			rollPts[roll] = argv[++idx];

			// Add score to the frame
			framePts += atoi(argv[idx]);

			// Special case when we get ten points or it is the last frame
			if (framePts == 10 || frame == 9) {
				if (frame < 9) {
					// Strike or spare
					if (roll == 0) {
						// Strike, add next two scores to frame if we can
						rollPts[roll] = "X";
						if (idx < argc - 2) {
							framePts += atoi(argv[idx + 1]) + atoi(argv[idx + 2]);
						}
					} else if (roll == 1) {
						// Spare, add next score to frame if we can
						rollPts[roll] = "/";
						if (idx < argc - 1) {
							framePts += atoi(argv[idx + 1]);
						}
					}
					
					// End the frame
					break;
				} else {
					// In the 10th frame if we rolled a strike, show a strike
					if (atoi(rollPts[roll]) == 10) {
						rollPts[roll] = "X";
					}
				}
			}
		}

		// Add the points from the frame to the score
		score += framePts;
		
		// Print the frame pretty
		printf("%-4d|%-4s|%-4s|%-4s|%-4d\n", frame + 1, rollPts[0], rollPts[1], rollPts[2], score); 
		
		// End the game if we have reached the end early
		if (endGame) {
			return 0;
		}
	}
}
