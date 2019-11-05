#include <stdio.h>
#include "des.h"

void single_sb(char in[6], char out[4], int box);

/* 	Input: 48-bit array
	Output: 32-bit array */
void sbox(char in[48], char out[32]) {
	char single_in[6], single_out[4];

	for(int i = 0; i < 8; ++i) {
		// Copy to single_in
		for(int j = 0; j < 6; ++j) {
			single_in[j] = in[j*i];
		}

		single_sb(single_in, single_out, i);

		//Copy to out
		for(int j = 0; j < 4; ++j) {
			out[j*i] = single_out[j];
		}
	}
}

/* 	Input: 6-bit data
	Output: 4-bit data */
void single_sb(char in[6], char out[4], int box) {
	int outer = in[0]*2 + in[1];
	printf("OUTER %d\n", outer);
}