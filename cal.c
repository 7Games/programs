/* Description: Shows a calender in the 
 * terminal with the current day highlighted.
 * Author: 7Games <benjamin@sevengames.xyz>
 * License: Unlicense
 */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Array of all the days in the corosponding months. */
int months[12] = {
	31,	/* January */
	28,	/* February (Will add 1 to it if it's a leap year) */
	31,	/* March */
	30,	/* April */
	31,	/* May */
	30,	/* June */
	31,	/* July */
	31,	/* August */
	30,	/* September */
	31,	/* October */
	30,	/* November */
	31	/* December */
};

/* Array of Months as a string. */
const char* month[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

/* Gets the first week day of the current month. */
int get_wdayOfMonth(int day) {
	int result = 0;
	for (int i = day; i > 0; i--) {
		result = ((day + i + 2) % 6);
	}
	return result;
}

/* Return a 1 or a 0 if the year is a leap year or not. */
int is_leapYear(int year) {
	return ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0));
}

int get_padding(int len, int wid) {
	return ((len >= wid) ? 0 : (wid - len) / 2);
}

int main(void) {
	/* Get the current date and time. */
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	/* Add 1 to February if it is a leap year. */
	months[1] += is_leapYear(tm.tm_year);

	/* Get padding for the month + year text. */
	int pad = get_padding(strlen(month[tm.tm_mon]), 20) - 3;

	/* Print month + year header. */
	printf("%*.*s%s %i\n", pad, pad, " ", month[tm.tm_mon], tm.tm_year + 1900);

	/* Prints day header. */
	printf("Su Mo Tu We Th Fr Sa\n");

	/* Adds white space before the first day. */
	for (int j = 0; j < 6; j++) {
		/* If were at the first day of the month, stop the loop. */
		if (get_wdayOfMonth(tm.tm_mday - 1) == j) {
			break;
		}
		printf("   ");
	}

	/* Goes through all the days in the month. */
	for (int i = 1; i <= months[tm.tm_mon]; i++) {
		/* If the current day is divisible by 7 which will
		 * indicate the end of a week, and add a newline. */
		if ((get_wdayOfMonth(tm.tm_mon) + i) % 7 == 0)
			printf("\n");
		/* Add a space before all the days with 1 character to line it up. */
		if (i < 10)
			printf(" ");
		/* If it is the current day make the
		 * background colors reverse with an ANSI escape code. */
		if (i == tm.tm_mday)
			printf("\x1b[7m");
		/* Print the day then a ANSI reset color escape code. */
		printf("%i\x1b[0m ", i);
	}

	/* Print new line. */ 
	printf("\n");

	return EXIT_SUCCESS;
}

