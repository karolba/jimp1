// author: Karol Baraniecki

#include <stdio.h>
#include <stdint.h>

#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24
#define DAYS_IN_WEEK 7

int main() {
	uint64_t input;
	scanf("%lu", &input);


	printf("%lu hours = %lu seconds\n", input, (input * SECONDS_IN_MINUTE * MINUTES_IN_HOUR));

	uint64_t minutes = input / SECONDS_IN_MINUTE;
	uint64_t hours = minutes / MINUTES_IN_HOUR;
	uint64_t days = hours / HOURS_IN_DAY;
	uint64_t weeks = days / DAYS_IN_WEEK;

	printf("%lu seconds = %lu weeks %lu days %02lu:%02lu:%02lu\n",
		input,
		weeks,
		days % DAYS_IN_WEEK,
		hours % HOURS_IN_DAY,
		minutes % MINUTES_IN_HOUR,
		input % SECONDS_IN_MINUTE);

	return 0;
}
