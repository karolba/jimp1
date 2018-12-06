/*********** primeChecking.h ***********/

#ifndef ISODDPRIMENUMBER_H
#define ISODDPRIMENUMBER_H

/** Tresc zadania:
Panstwa zadaniem jest napisanie funkcji isOddPrimeNumber(), ktora zwroci true dla kazdej liczby pierwszej nieparzystej.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie primeChecking.h, bez robienia w nim jakichkolwiek zmian.
**/

#ifdef __STDC__
    #include <stdbool.h>
#endif


#ifdef __cplusplus
    extern "C"
    {
#endif
        bool isOddPrimeNumber(int number);
#ifdef __cplusplus
    }
#endif

#endif // ISODDPRIMENUMBER_H


/*********** primeChecking.c ***********/

// author: Karol Baraniecki

#include <stdio.h>
#include <math.h>

bool isOddPrimeNumber(int number) {
    if(number < 3)
        return false;

    double sq = sqrt(number);

    for(int i = 3; i < sq; i += 2) {
        if (number % i == 0)
            return false;
    }
    return true;
}
