// author: Karol Baraniecki

#include <stdio.h>
#include <math.h>

void disp(int kmh, char *dashline) {
    printf("|%4dkm/h|%4dm/h|\n", kmh, (int) (0.623 * kmh));
    puts(dashline);
}

int main() {
    char dashline[] = { [0 ... 17] = '-', '\0' };

    puts(dashline);
    disp(140, dashline);
    disp(100, dashline);
    disp(90, dashline);
    disp(50, dashline);
    disp(20, dashline);

    return 0;
}
