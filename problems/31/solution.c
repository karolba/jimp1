#ifndef WORD_SORTING_H
#define WORD_SORTING_H

/** Tresc zadania:
Panstwa zadaniem jest napisanie funkcji sortWords(), ktora zrobi to, co mowi jej nazwa, czyli przyjmie tablice wyrazow i je posortuje zwracajac informacje ile w sumie jest tam wyrazow. Ilosc wyrazow poznamy po tym, ze ostatni element wskazuje na NULL. 

Przypadki testowe:
    - Prosze w razie podania words==NULL zwrocic 0 slow.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie wordSorting.h, bez robienia w nim jakichkolwiek zmian.

Polecam uzyc gotowca do porownywania tekstu z: http://www.cplusplus.com/reference/cstring/
**/

#ifdef __cplusplus
    extern "C"
    {
#endif
        long sortWords(char **words);
#ifdef __cplusplus
    }
#endif

#endif // WORD_SORTING_H

// author: Karol Baraniecki

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int compare(const void *p1, const void *p2) {
    return strcmp(* (char * const *)p1, * (char * const *)p2);
}

size_t len(char **words) {
    size_t i = 0;
    while(words[i++] != NULL);
    return i - 1;
}

long sortWords(char **words) {
    if(words == NULL)
        return 0;

    size_t l = len(words);

    qsort(words, l, sizeof(char *), compare);
    
    return l;  
}
