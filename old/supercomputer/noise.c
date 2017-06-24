#include <stdlib.h>
#include <stdio.h>

int putbit (int b) {
	static int shiftreg = 0x01;
	shiftreg <<= 1;
	if (b) {
		shiftreg |= 0x01;
	}
	if (shiftreg & 0x100) {
		putchar (shiftreg & 0xff);
		shiftreg = 0x01;
	}
}

int main (int argc, char *argv []) {
	int ch, ch2;
	char skip [56];
	unsigned long data;
	unsigned int ones = 0;
	unsigned int zeroes = 0;
	if (read (0, skip, 56) < 56) {
		fprintf (stderr, "Could not skip header of WAV file\n");
		exit (1);
	}
	while (read (0, &data, 4) == 4) {
		ch = data & 0x02;
		ch2 = (data >> 16) & 0x02;
		if (ch != ch2) {
			putbit (ch);
			if (ch) {
				ones++;
			} else {
				zeroes++;
			}
		}
	}
	fprintf (stderr, "ones = %ld, zeroes = %ld\n", ones, zeroes);
}
