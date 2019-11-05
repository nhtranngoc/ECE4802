/*
ECE4802 - Cryptography
Homework 2
Part 1
Nam Tran Ngoc
 */
#define DES_SOURCE
#include <stdio.h>
#include "des.h"

// Plaintext input, 32-bit
char INPUT[32] = {
	1, 1, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 0, 1, 0, 0, 0,
	0, 1, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 0, 1, 0, 0, 1
};

/**
 * @brief      Main program goes here
 *
 * @return     None
 */
int main() {
	char output_e[48], output_s[32], output_p[32];

	printf("INPUT\n");
	printa((char *)INPUT, 32, 8);

	printf("\n\nEXPANSION\n");
	expand(INPUT, output_e);
	printa(output_e, 48, 6);

	printf("\n\nXOR\n");
	xor(output_e, ROUND_K);
	printa(output_e, 48, 6);

	printf("\n\nSBOX\n");
	sbox(output_e, output_s);
	printa(output_s, 32, 8);

	printf("\n\nPERMUTE\n");
	permute(output_s, output_p);
	printa(output_p, 32, 8);

}

/**
 * @brief      Expand input to output using expansion table
 *
 * @param      in    Input bitfield, 32-bit long
 * @param      out   Output bitfield, 48-bit long
 */
void expand(char in[32], char out[48]) {
	for(int i = 0; i < 48; ++i) {
		out[i] = INPUT[EXPAND_T[i] - 1];
	}
}

/**
 * @brief       XOR input with key
 * @param 		in 	Input bitfield, 48-bit long
 * @param 	 	k 	Key to XOR
 */
void xor(char in[48], const char k[48]) {
	for(int i = 0; i < 48; ++i) {
		in[i] ^= k[i];
	}
}

/**
 * @brief      Permute input using a given Permutation Table
 *
 * @param      in    Input bitfield, 32-bit long
 * @param      out   Output bitfield, 32-bit long
 */
void permute(char in[32], char out[32]) {
	for(int i = 0; i < 32; ++i) {
		out[i] = in[PERMUTE_T[i] - 1];
	}
}

/**
 * @brief      Print bitfield array and make it look nice
 *
 * @param      a       Input bitfield
 * @param[in]  size    Size of the bitfield
 * @param[in]  line_s  Number of bits per line
 */
void printa(char a[], int size, int line_s) {
	for(int i =0; i < size; ++i) {
		if((i % line_s) == 0 && i > 0) puts("");
		printf("%d ", a[i]);
	}
}