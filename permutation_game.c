#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 Copyright (c) 2015 Shane Carey
 
 Alice and Bob play the following game:

 They choose a permutation of the first N numbers to begin with.
 They play alternately and Alice plays first.
 In a turn, they can remove any one remaining number from the permutation.
 The game ends when the remaining numbers form an increasing sequence. The person who played the last turn (after which the sequence becomes increasing) wins the game.

 Assuming both play optimally, who wins the game?
*/

typedef enum {ALICE, BOB} player_t;

int arrayIncreasing(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int permutationWinner(int seq[], int len, player_t turn) {
    for (int i = 0; i < len; i++) {
        int subSeq[len - 1];
	for (int j = 0; j < len - 1; j++) {
	    if (j < i) {
		subSeq[j] = seq[j];
	    } else {
		subSeq[j] = seq[j + 1];
	    }
	}
	if (arrayIncreasing(subSeq, len - 1)) {
	     return turn;
	} else if (permutationWinner(subSeq, len - 1, !turn) == turn) {
	     return turn;
	}
    }
    return !turn;
}

int main(int argc, char *argv[]) {

    int seq[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
	seq[i] = atoi(argv[i + 1]);
    }

    int winner = permutationWinner(seq, argc - 1, ALICE);
    printf("%s\n", winner ? "BOB" : "ALICE");

    return 0;
}
