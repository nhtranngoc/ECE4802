/*
ECE4802 - Cryptography
Homework 1
Part 1
Nam Tran Ngoc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 1000
// Stock letter freq of the English language
const char
    ALPHA_FREQ[] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd', 'l', 'c', 'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b', 'v', 'k', 'j', 'x', 'q', 'z'};  
const char
    GUESS_FREQ[] = {'e', 't', 'a', 'n', 'o', 'r', 's', 'i', 'c', 'l', 'h', 'd', 'u', 'm', 'p', 'g', 'w', 'f', 'y', 'v', 'b', 'k', 'x', 'j', 'q', 'z'};  

typedef struct Freq {
  char c;
  int f;
} Freq;

struct Freq *CIPHER_FREQ = NULL;  // unsorted cipher frequency
char CIPHER_TEXT[MAX_CHAR];

char lower(char c);
void printFreq();
int compare(const void *p1, const void *p2);
char replace(char c, const char f[]);

int main() {
  // Initialize frequency counter
  CIPHER_FREQ = malloc(26 * sizeof(Freq));
  for (int i = 0; i < 26; ++i) {
    CIPHER_FREQ[i].c = 'a' + i;
    CIPHER_FREQ[i].f = 0;
  }

  char c;
  int j = 0;
  while ((c = lower(getchar())) != EOF) {
    // Count frequency of characters then put it in CIPHER_FREQ
    if (c >= 'a' && c <= 'z') {
      // If it's a letter, count the frequency
      ++CIPHER_FREQ[c - 'a'].f;
    }
    // At the same time, copy cipher for later use.
    CIPHER_TEXT[j] = c;
    ++j;
  }
  CIPHER_TEXT[j] = '\0';

  // Sort frequency analysis
  qsort(CIPHER_FREQ, 26, sizeof(Freq), compare);
  printFreq(CIPHER_FREQ);

  for (int i = 0; CIPHER_TEXT[i] != '\0'; ++i) {
    putchar(replace(CIPHER_TEXT[i], GUESS_FREQ));
  }

  return 0;
}

// Convert to lowercase for ease of mathsss
char lower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  } else
    return c;
}

void printFreq() {
  for (int i = 0; i < 26; ++i) {
    // printf("Char %c appeared %d times.\n", CIPHER_FREQ[i].c,
    // CIPHER_FREQ[i].f);
    printf("Char %c -> %c\n", CIPHER_FREQ[i].c, ALPHA_FREQ[i]);
  }
}

// Compare function for quicksort()
int compare(const void *p1, const void *p2) {
  const Freq *elem1 = p1;
  const Freq *elem2 = p2;

  if (elem1->f > elem2->f) {
    return -1;
  } else if (elem1->f < elem2->f) {
    return 1;
  } else
    return 0;
}

// Replace text based on frequency analysis
// Replace char c using frequency found in f
char replace(char c, const char f[]) {
  for (int i = 0; i < 26; ++i) {
    if (CIPHER_FREQ[i].c == c) {
      return f[i];
    }
  }
  return c;
}        