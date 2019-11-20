#include <stdio.h>

int m_inverse(int a, int b);
int gcd(int a, int b);

int main() {
	printf("15*29 mod 13 = %d\n", 15*29%13);
	printf("15*29 mod 12 = %d\n", 15*29%12);
	printf("15*28 mod 12 = %d\n", 15*28%12);
	printf("(15*29+7*12) mod 13 = %d\n", (15*29+7*12)%13);

	printf("\n5^-1 mod 19 = %d\n", m_inverse(5, 19));
	printf("5^-1 mod 12 = %d\n", m_inverse(5, 12));
	printf("5^-1 mod 17 = %d\n", m_inverse(5, 7));
	printf("5^-1 mod 10 = %d\n", m_inverse(5, 10));

	int Z[3] = {44, 56, 96};

	for(int i = 0; i < 3; ++i) {
		printf("\nElements without inverse in Z%d: ", Z[i]);
		for(int j = 0; j < Z[i]; ++j) {
			if(m_inverse(j,Z[i]) == -1) {
				printf("%d, ", j);
			}
		}
		printf("\n");
	}
	
	return 0;
}

int m_inverse(int a, int b) {
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;

	if(gcd(a,b) != 1) {
		// printf("There's no multiplicative inverse!\n");
		return -1;
	}

	if(b == 1) {
		return 1;	
	} 

	while(a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}

	if(x1 < 0) {
		x1 += b0;	
	} 

	return x1;
}

int gcd(int x, int y) {
	if(x == 0) {
		return y;
	} else if(y == 0) {
		return x;
	}

	gcd(y, x%y);
}