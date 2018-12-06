// author: Karol Baraniecki

#define _GNU_SOURCE
#include <stdio.h>

int main() {
    char name[64];
    scanf("%[^\n]s", name);

    int birthday, birthmonth, birthyear;
    scanf("%d %d %d", &birthday, &birthmonth, &birthyear);

    int month, year;
    scanf("%d %d", &month, &year);

    int after_months;
    scanf("%d", &after_months);

    int months_old = (year * 12 + month) - (birthyear * 12 + birthmonth);
    
    printf("%s ma %d lat i %d miesiecy\n", name, months_old / 12, months_old % 12);

    months_old += after_months;
    printf("za %d miesiecy %s bedzie mial %d lat i %d miesiecy\n", after_months, name, months_old / 12, months_old % 12);

    return 0;
}
