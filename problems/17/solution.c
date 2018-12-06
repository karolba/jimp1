// author: Karol Baraniecki

#include <stdio.h>

static int month_lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    int month, weekday;
    scanf("%d %d", &month, &weekday);
    printf("Miesiac %d\n", month);

    puts("|Ni|Po|Wt|Sr|Cz|Pt|So|");

    for(int i = 0; i < weekday; i++) {
        printf("|  ");
    }

    int i;
    for(i = weekday + 1; i <= weekday + month_lengths[month - 1]; i++) {
        printf("|%2d", i- weekday);
        if(i % 7 == 0) {
            puts("|");
        }
    }

    if((i - 1) % 7 != 0) {
        for(int j = 0; j < 7 - ((i - 1) % 7); j++) {
            printf("|  ");
        }

        puts("|");
    }


    return 0;
}
