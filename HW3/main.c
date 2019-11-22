#include "main.h"

int main(int argc, char **argv) {

	printf("=================== HOMEWORK 3 ===================\n\n");

	printf("\n------------------> Part 1 <------------------\n");

	uint8_t output[4][4];
	sbox(INPUT, output);

	printf("\n------------------> Part 2 <------------------\n");

	printf("%d^-1 mod %d: %d\n", 17, 37, eea(17,37));
	printf("%d^-1 mod %d: %d\n", 13, 91, eea(13,91));
	printf("%d^-1 mod %d: %d\n", 13, 448, eea(13,448));
	printf("%d^-1 mod %d: %d\n", 16, 4725, eea(16,4725));
	return 0;
}

void sbox(uint8_t input[4][4], uint8_t output[4][4]) {
	int x,y;
	for(x = 0; x < 4; x++) {
		for(y = 0; y < 4; y++) {
			uint8_t inputX = input[x][y] >> 4;
			uint8_t inputY = input[x][y] & 0xf;
			output[x][y] = SBOX[inputX][inputY];
			printf("0x%02x ", output[x][y]);
			if(y == 3) {
				puts("");
			}
		}
	}
}

// Find multiplicative input using Extended Euclidean Algorithm
int eea(int a, int b) {
	// Initialize variables to use in eea
	int q,
		t, 
		x0 = 0,
		x1 = 1, 
		b0 = b; // Save original b for later

	// Not coprime
	if(gcd(a,b) != 1) {
		printf("%d and %d are not coprime, there's no multiplicative inverse\n", a, b);
		return -1;
	}

	// Fringe case
	if(b == 1) {
		return 1;
	}

	// Extended Euclidean
	while(a > 1) {
		q = a / b;
		swap(&a, &b);
		b = b % a;
		swap(&x0, &x1);
		x0 = x0 - q * x1;
	}

	// Wrap around in modular space
	if(x1 < 0) {
		x1+= b0;
	}

	return x1;
}

// Helper function to swap 2 numbers
void swap(int *a, int *b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

// Recursive function to find gcd()
int gcd(int a, int b) {
	int rem = b%a;
	// We found gcd! 
	if(rem == 0) {
		return a;
	}
	gcd(rem, a);
}