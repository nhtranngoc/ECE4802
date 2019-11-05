/*
ECE4802 - Cryptography
Homework 1
Part 2
Nam Tran Ngoc
 */

#include <stdio.h>
#include <stdint.h>

#define INIT_STATE 0b000110100
#define LFSR_MASK  0b100011101

unsigned lfsr(void);
void printbits(size_t const size, void const * const ptr);

int main() {
	printf("%d", lfsr());
	return 0;
}

unsigned int lfsr(void) {
	uint16_t bit;
	uint16_t lfsr = INIT_STATE;
	unsigned period = 0;
	char s[17];

	do {

		// for(int i = 0; i < 9; i++) {
		// 	s[8 - i] = (lfsr & (1 << i)) ? '1' : '0';
		// }

		// s[10]= '\0';
		// printf("%10d: %s\n", period, s);
		printf("%10d: ", period);
		printbits(sizeof lfsr, &lfsr);

		// Taps: 8 4 3 2 feedback polynomial x^8 + x^4 + x^3 + x^2 + 1
		unsigned lsb = lfsr & 1;
		// bit = ((lfsr >> 8) ^ (lfsr >> 4) ^ (lfsr >> 3) ^ (lfsr >> 2)) & 1;
		
		//=============MESS AF
		uint16_t bit8 = lfsr >> 8;
		uint16_t bit4 = lfsr >> 4;
		uint16_t bit3 = lfsr >> 3;
		uint16_t bit2 = lfsr >> 2;

		// printbits(sizeof lfsr, &lfsr);
		// printbits(sizeof lfsr, &bit4);

		bit = ((lfsr >> 8) ^ (lfsr >> 4) ^ (lfsr >> 3) ^ (lfsr >> 2)) & 1;
		lfsr >>= 1;
		lfsr ^= (-bit ^ lfsr) & (1 << 8);
		// lfsr = (lfsr >> 1) | (bit << 8);
		++period;
		// printf("%d\n", lfsr);

	// } while(lfsr != INIT_STATE);
	} while(period <= 15);

	return period;
}

// Print binary, size is the number of bits
void printbits(size_t const size, void const * const ptr) {
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for(i=size-1;i>=0;i--) {
		for(j=7;j>=0;j--) {
			byte = (b[i] >> j) & 1;
			if(j == 3 || j == 7) {
				printf(" ");
			}
			printf("%u", byte);
		}
	}
	puts("");
}