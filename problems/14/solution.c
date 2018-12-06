// author: Karol Baraniecki
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <math.h>
#include <assert.h>

static int rountToInt(double a) {
    return (int)(a + 0.5);
}

static int km2miles(double km) {
    int miles = rountToInt(0.621371192 * km / 5.0) * 5;
    return miles;
}

int main() {
    char line1[16];
    char line2[16];

    double kmh;

    assert(scanf("%13s", line1) != EOF);
    assert(scanf("%*[^\n]") != EOF); // ignore rest of the line

    assert(scanf("%13s", line2) != EOF);
    assert(scanf("%*[^\n]") != EOF);

    assert(scanf("%lf", &kmh) != EOF);

    char dashline[] = { [0 ... 14] = '-', '\0' };
    puts(dashline);

    printf("|%13s|\n", line1);
    printf("|%13s|\n", line2);

    puts(dashline);

    printf("|  km/h|   m/h|\n");

    puts(dashline);

    int miles = km2miles(kmh);
    printf("|%6d|%6d|\n", rountToInt(kmh), miles);

    puts(dashline);

    return 0;
}
