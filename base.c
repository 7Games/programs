/* Description: Get files name or extension'.
 * Author: 7Games <benjamin@sevengames.xyz>
 * License: Unlicense
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <libgen.h>
#include <unistd.h>

void die(const char* errorString, ...) {
	va_list ap;

	va_start(ap, errorString);
	fprintf(stderr, errorString, va_arg(ap, char*));
	va_end(ap);

	exit(EXIT_FAILURE);
}

char* getFileName(char* filePath) {
	char* fileName = basename(filePath);
    char* fileNameNoExt = strtok(fileName, ".");

	return fileNameNoExt;
}

char* getFileExt(char* filePath) {
	char* fileName = basename(filePath);
	char* token;
	char* ext = NULL;
	while ((token = strtok(fileName, ".")) != NULL) {
		ext = token;
		fileName = NULL;
	}

	if (ext)
		return ext;
	
	return "";
}

int fileExists(char* filePath) {
	if (access(filePath, F_OK) == 0) {
		return 1;
	}

	return 0;
}

int main(int argc, char** argv) {
	if (argc < 3)
		die("usage: %s --(name|extension) [FILE]\n", argv[0]);

	if (fileExists(argv[2]) == 0)
		die("File '%s' does not exist.\n", argv[2]);

	char* string;

	if (strcmp(argv[1], "--name") == 0) {
		string = getFileName(argv[2]);
	} else if (strcmp(argv[1], "--extension") == 0) {
		string = getFileExt(argv[2]);
	} else {
		die("usage: %s --(name|extension) [FILE]\n", argv[0]);
	}

	puts(string);

	return 0;
}

