// author: Karol Baraniecki

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/******************* pointersSorting.h ****************/
#ifndef POINTERS_SORTING_H
#define POINTERS_SORTING_H

/** Tresc zadania:
Panstwa zadaniem jest napisanie funkcji sortPointers(), przyjmie dwa wskazniki -na poczatek i za koniec tablicy i zwroci ilosc elementow. Poza tym funkcja ma za zadanie wstawic w parametrze pointers wskazniki do elementow tablicy z zakresu [from, to), ale w posortowanej kolejnosci. W razie podania odwrotnego zakresu (from > to) funkcja rowniez powinna sobie poradzic. W razie podania NULLa ma zostac zwrocone 0 i ma nie byc nic zmieniane z parametrem pointers.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie pointersSorting.h, bez robienia w nim jakichkolwiek zmian.
**/

typedef double T;

#ifdef __cplusplus
    extern "C"
    {
#endif
        size_t sortPointers(const T* from, const T* to, T*** pointers);
#ifdef __cplusplus
    }
#endif

#endif // POINTERS_SORTING_H


/******************* pointersSorting.c ****************/


static int comp(const void *a, const void *b) {
    const T *ta = (const T *)a;
    const T *tb = (const T *)b;

    if(*ta < *tb)
        return -1;
    if(*ta > *tb)
        return 1;
    return 0;
}

size_t sortPointers(const T* from, const T* to, T*** pointers) {
    if(from == NULL || to == NULL)
        return 0;

    if(from > to) {
        const T* tmp = from;
        from = to;
        to = tmp;
    }

    size_t len = (to - from);
    T *copy = (T *) malloc(len * sizeof(T));
    memcpy(copy, from, len * sizeof(T));

    T **pointers_arr = (T **) malloc(len * sizeof(T *));

    qsort(copy, len, sizeof(T), comp);

    for(int i = 0; i < len; i++) {
        pointers_arr[i] = copy + i;
    }

    *pointers = pointers_arr;

    return len;
}
