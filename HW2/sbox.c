#include <stdio.h>
#include "des.h"

void single_sb(char in[6], char out[4], int box);

/**
 * @brief      S-Box function, using given S-boxes
 *
 * @param      in    Input bitfield, 48-bit long
 * @param      out   Output bitfield, 32-bit long
 */
void sbox(char in[48], char out[32]) {
	char single_in[6], single_out[4];

	// Break down to smaller boxes
	for(int i = 0; i < 8; ++i) {
		// Copy to single_in
		for(int j = 0; j < 6; ++j) {
			single_in[j] = in[j+i*6];
		}

		single_sb(single_in, single_out, i);

		//Copy to out
		for(int j = 0; j < 4; ++j) {
			out[j+i*4] = single_out[j];
		}

	}
}

/**
 * @brief      Handle individual s-boxes
 *
 * @param      in    Input bitfield, 6-bit long
 * @param      out   Output bitfield, 4-bit long
 * @param[in]  box   Box number, 0-7
 */
void single_sb(char in[6], char out[4], int box) {
	int outer = in[0]*2 + in[5];
	int inner = in[1]*8 + in[2]*4 + in[3]*2 + in[4];

	int index = outer*16 + inner;
	int val = SB[box][index];


	for(int i = 0; i < 4; ++i) {
		out[3-i] = (val >> i) & 1;
	}

	printf(	"BOX %d\t"
	 		"OUT %d\t"
	 		"IN %d\t"
	 		"INDEX  %d\t"
	 		"VAL %d\t BIN ", box, outer, inner, index, val);
	printa(out,4,4);
	puts("");
}