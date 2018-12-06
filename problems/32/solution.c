// author: Karol Baraniecki

#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*********************** splitWords.h ********************/


#ifndef SPLIT_WORDS_H
#define SPLIT_WORDS_H

/** Tresc zadania:
Panstwa zadaniem jest napisanie funkcji splitTextIntoWords(), ktora zrobi to, co mowi jej nazwa, czyli przyjmie ciag znakow i podzieli na wyrazy zwracajac informacje ile w sumie jest tam wyrazow. Parametr words powinien zostać odpowiednio zainicjalizowany. Podzial na wyrazy ma sie odbywac w oparciu o funkcje http://www.cplusplus.com/reference/cctype/isalnum/ . Jesli tekst nie bedzie zawieral zadnego z wyrazow, to parametr words powinien byc zainicjalizowany wartoscia NULL.

Przypadki testowe:
    - text == NULL
    - text jest pusty
    - brak wyrazow
    - jeden wyraz
    - normalne zdanie
    - wzor matematyczny

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie splitWords.h, bez robienia w nim jakichkolwiek zmian.

Podpowiedzi:
    - polecam uzyc gotowca do kopiowania tekstu: http://www.cplusplus.com/reference/cstring/
    - polecam miec oddzielna funkcje, ktora zliczy ilosc wyrazow, ktora zostanie uzyta przez splitTextIntoWords
    - jak ktos chce moze sie pobawic najbardziej-duzo-robiaca funkcja jezyka C, czyli realloc: http://www.cplusplus.com/reference/cstdlib/realloc/
**/

#ifdef __cplusplus
    extern "C"
    {
#endif
        long splitTextIntoWords(const char* text, char*** words);
#ifdef __cplusplus
    }
#endif

#endif // SPLIT_WORDS_H



/*********************** splitWords.c ********************/


long splitTextIntoWords(const char* text, char*** words) {
    if(text == NULL)
        return 0;

    char *copy = strdup(text);
    size_t len = strlen(text);

    size_t nwords = 0;

    for(size_t i = 0; i < len; i++) {
        if(!isalnum(copy[i])) {
            copy[i] = '\0';
        }
    }
    for(size_t i = 1; i <= len; i++) {
        if(copy[i - 1] != '\0' && copy[i] == '\0')
            nwords++;
    }

    if(nwords == 0) {
        free(copy);
        return 0;
    }

    char **wds = (char **) malloc(sizeof(char *) * (nwords + 1));
    bzero(wds, sizeof(char *) * (nwords + 1));
    
    size_t j = 0;
    size_t start = 0;
    for(size_t i = 1; i <= len; i++) {
        if(copy[i] == '\0' && copy[i - 1] != '\0')
            wds[j++] = strdup(copy + start);

        if(copy[i] != '\0' && copy[i - 1] == '\0')
            start = i;
    }

    *words = wds;

    free(copy);

    return nwords;
}
