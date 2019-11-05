/*
ECE4802 - Cryptography
Homework 2
Part 1
Nam Tran Ngoc
 */

#include <stdio.h>

void expand(char in[], char out[]); //Expand 32 to 48 bits
void printa(char a[], int size, int line_s); // Print array
void xor(char c[], const char k[]);

// const char s1[64] = {
// 	14, 4 , 13, 1 , 2 , 15, 11, 8 , 3 , 10, 6 , 12, 5 , 9 , 0 , 7 ,
// 	0 , 15, 7 , 4 , 14, 2 , 13, 1 , 10, 6 , 12, 11, 9 , 5 , 3 , 8 ,
// }

const char EXPAND_T[48] = {
	32, 1 , 2 , 3 , 4 , 5 ,
	4 , 5 , 6 , 7 , 8 , 9 ,
	8 , 9 , 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1};

char INPUT[32] = {
	1, 1, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 0, 1, 0, 0, 0,
	0, 1, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 0, 1, 0, 0, 1};

const char ROUND_K[48] = {
	1, 1, 0, 0, 1, 1,
	1, 0, 1, 1, 1, 1,
	1, 1, 0, 1, 0, 0,
	0, 1, 0, 0, 1, 1,
	1, 0, 1, 0, 0, 0,
	1, 1, 1, 0, 0, 0,
	1, 0, 0, 0, 1, 0,
	0, 1, 0, 1, 0, 1
};

int main() {
	char output[48];

	printf("INPUT\n");
	printa((char *)INPUT, 32, 8);

	printf("\n\nEXPANSION\n");
	expand(INPUT, output);
	printa(output, 48, 6);

	printf("\n\nXOR\n");
	xor(output, ROUND_K);
	printa(output, 48, 6);

}

void expand(char in[], char out[]) {
	for(int i = 0; i < 48; ++i) {
		out[i] = INPUT[EXPAND_T[i] - 1];
	}
}

void xor(char c[], const char k[]) {
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