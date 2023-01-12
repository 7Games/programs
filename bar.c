/* Description: Prints bar with user defined ammount.
 * Author: 7Games <benjamin@sevengames.xyz>
 * License: Unlicense
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void die(const char* errorString, ...) {
	va_list ap;

	va_start(ap, errorString);
	fprintf(stderr, errorString, va_arg(ap, char*));
	va_end(ap);

	exit(EXIT_FAILURE);
}

void printBar(const char* numberOfBlocks) {
	char *end;
	int blocks = strtol(numberOfBlocks, &end, 10);

	if (end == numberOfBlocks || *end != '\0' || errno == ERANGE)
		die("not a number\n");
	if (blocks < 0 || blocks > 10)
		die("number not in range\n");

	printf("[");

	for (int i = 0; i < 10; i++) {
		if (i < blocks)
			printf("#");
		else
			printf("-");
	}

	printf("]\n");
}

int main(int argc, char **argv) {
	if (argc != 2)
		die("usage: %s [NUMBER]\n", argv[0]);

	printBar(argv[1]);

	exit(EXIT_SUCCESS);
}

