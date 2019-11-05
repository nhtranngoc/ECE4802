/*
ECE4802 - Cryptography
Homework 2
Part 1
Nam Tran Ngoc
 */
#define DES_SOURCE
#include <stdio.h>
#include "des.h"

char INPUT[32] = {
	1, 1, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 0, 1, 0, 0, 0,
	0, 1, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 0, 1, 0, 0, 1
};


int main() {
	char output[48], output_s[32];

	printf("INPUT\n");
	printa((char *)INPUT, 32, 8);

	printf("\n\nEXPANSION\n");
	expand(INPUT, output);
	printa(output, 48, 6);

	printf("\n\nXOR\n");
	xor(output, ROUND_K);
	printa(output, 48, 6);

	sbox(output, output_s);

}

void expand(char in[32], char out[48]) {
	for(int i = 0; i < 48; ++i) {
		out[i] = INPUT[EXPAND_T[i] - 1];
	}
}

void xor(char c[48], const char k[48]) {
	for(int i = 0; i < 48; ++i) {
		c[i] ^= k[i];
	}
}

void printa(char a[], int size, int line_s) {
	for(int i =0; i < size; ++i) {
		if((i % line_s) == 0 && i > 0) puts("");
		printf("%d ", a[i]);
	}
}