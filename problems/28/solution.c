// author: Karol Baraniecki

// *** textsearching.h *** //

#ifndef TEXT_SEARCHING_H
#define TEXT_SEARCHING_H

/** Tresc zadania:
Panstwa zadaniem jest napisanie funkcji findWordInTextReturningPosition(), ktora dla podanego tekstu znajdzie szukane slowo, ale:
1) jesli dane slowo znajduje sie w tekscie prosze zwrocic indeks pozycji na ktorym sie znajduje
2) jesli nie znaleziono prosze zwrocic -1
3) funkcja ma ignorowac wielkosc liter, podpowiedz:
   http://www.cplusplus.com/reference/cctype/tolower/
4) Jako kolejny argument podajemy kierunek wyszukiwania tekstu

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie basename.h, bez robienia w nim jakichkolwiek zmian.


Podpowiedzi:
- Polecam maksymalnie rozbic to na funkcje
- Polecam tez zastosowac duza ilosc funkcji do operowania na tekscie: http://www.cplusplus.com/reference/cstring/
  mozna sobie np. skopiowac tekst do innej tablicy zamieniajac na male litery i na tym szukac przy uzyciu gotowych funkcji do wyszukiwania.
**/

enum TextSearchingDirection
{
    TEXT_SEARCHING_DIRECTION_FROM_BEGINNING,
    TEXT_SEARCHING_DIRECTION_FROM_END
};


#ifdef __STDC__
    typedef enum TextSearchingDirection TextSearchingDirection;
#endif


#ifdef __cplusplus
    extern "C"
    {
#endif
        int findWordInTextReturningPosition(const char text[], const char word[], TextSearchingDirection searchDirection);
#ifdef __cplusplus
    }
#endif

#endif // TEXT_SEARCHING_H



// *** textsearching.c *** //

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

//#include "problem.h"

int findWordInTextReturningPosition(const char text[], const char word[], TextSearchingDirection searchDirection) {
    size_t wordlen = strlen(word);
    size_t textlen = strlen(text);

    if(searchDirection == TEXT_SEARCHING_DIRECTION_FROM_BEGINNING) {
        for(int i = 0; i < textlen; i++) {
            if(wordlen + i > textlen)
                continue;
            if(strncasecmp(text + i, word, wordlen) == 0)
                return i;
        }
    } else if(searchDirection == TEXT_SEARCHING_DIRECTION_FROM_END) {
        for(int i = textlen - 1; i > 0; i--){
            if(wordlen + i > textlen)
                continue;
            if(strncasecmp(text + i, word, wordlen) == 0)
                return i;
        }
    }

    return -1;
}
