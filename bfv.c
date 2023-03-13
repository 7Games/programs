#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

void die(const char* ERROR_STRING, ...) {
	va_list ap;
	
	va_start(ap, ERROR_STRING);
	fprintf(stderr, ERROR_STRING, va_arg(ap, char*));
	va_end(ap);

	exit(EXIT_FAILURE);
}

FILE* openFile(const char* file_path) {
	FILE* f;
	f = fopen(file_path, "r");

	if (!f)
		die("File %s does not exist\n", file_path);
	
	return f;
}

void printFormatedChar(char ch) {
	switch (ch) {
	case '$': 
		printf("\x1b[1m"); break;	// Bold.
	case '!':
		printf("\x1b[0m"); break;	// Reset formatting.
	case '>':
		printf("\x1b[4m"); break;	// Underline.
	case '~':
		printf("\x1b[9m"); break;	// Strikethrough.
	case '/':
		printf("\x1b[3m"); break;	// Italics.
	case '*':
		printf("\x1b[5m"); break;	// Blinking text.
	case '&':
		printf("\x1b[7m"); break;	// Reverse colors.
	default:
		printf("%c", ch);  break;	// Print normal char.
	}
}

void colorText(char* color_buf) {
	int code = 30;
	char colors[8][8] = {
		"black",
		"red",
		"green",
		"yellow",
		"blue",
		"magenta",
		"cyan",
		"white"
	};

	if (color_buf[0] == 'b') {
		code += 10;
	} else if (color_buf[0] != 'f') {
		die("Color is not in foreground or background!\n");
	}

	++color_buf;

	for (int i = 0; i < 8; i++) {
		if (strcmp(color_buf, colors[i]) == 0) {
			printf("\x1b[%im", code + i);
			return;
		}
	}

	die("%s is not a valid color!\n", color_buf);
}

void printFile(FILE* file) {
	char line[255];

	while (fgets(line, 255, (FILE*)file)) {
		bool escape = false;
		bool color = false;

		char colorBuf[20];

		for (int i = 0; i < (int)strlen(line); i++) {
			char ch = line[i];

			if (ch == '\\') {
				if (escape == false) {
					escape = true;
					continue;
				}
			}

			if (escape == true) {
				printf("%c", ch);
				escape = false;
				continue;
			}

			if (ch == '%') {
				if (color == false) {
					color = true;
					strcpy(colorBuf, "");
					continue;
				} else {
					colorText(colorBuf);
					strcpy(colorBuf, "");
					color = false;
					continue;
				}
			}

			if (color == true) {
				strncat(colorBuf, &ch, 1);
				continue;
			}

			printFormatedChar(ch);
		}
		printFormatedChar('!');
	}

	fclose(file);
}

int main(int argc, char** argv) {
	if (argc == 1 || strcmp(argv[1], "-") == 0) {
		printFile(stdin);
		exit(EXIT_SUCCESS);
	}

	printFile(openFile(argv[1]));
	
	exit(EXIT_SUCCESS);
}

