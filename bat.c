/* Description: Clone of POSIX cat.
 * Author: 7Games <benjamin@sevengames.xyz>
 * License: Unlicense
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 4080
#define FILE_PATH_LENGTH 2048

void die(const char* errorString, ...) {
	va_list ap;

	va_start(ap, errorString);
	fprintf(stderr, errorString, va_arg(ap, char*));
	va_end(ap);

	exit(EXIT_FAILURE);
}

void printFileToScreen(const char* filePath) {
	FILE* file;
	char currentLine[LINE_LENGTH];

	/* If the file path is '-' set the file to standard input. */
	if (strcmp(filePath, "-") == 0) {
		file = stdin;
	} else {
		file = fopen(filePath, "r");
	}

	if (file == NULL)
		die("Cannot read file \"%s\"\n", filePath);

	while (fgets(currentLine, sizeof(currentLine), file) != NULL) {
		printf("%s", currentLine);
	}

	fclose(file);
}

int main(int argc, const char** argv) {
	int numberOfFiles = 0;
	char files[argc][FILE_PATH_LENGTH];

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i],"-u") == 0) {
			/* Disable buffer on standard output as stated in cat(1p) */
			setvbuf(stdout, NULL, _IONBF, 0);
		} else {
			strcpy(files[numberOfFiles], argv[i]);
			numberOfFiles++;
		}
	}

	/* If there are no files, then read from standard input. */
	if (numberOfFiles == 0) {
		strcpy(files[0], "-\0");
		numberOfFiles++;
	}

	for (int i = 0; i < numberOfFiles; i++) {
		printFileToScreen(files[i]);
	}

	return 0;
}

