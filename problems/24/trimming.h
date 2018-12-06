/**
Tresc zadania:
Panstwa zadaniem jest napisanie funkcji, ktora podany tekst obetnie z przodu i z tylu bialych znakow, oraz zwroci informacje ile znakow obciela. Sygnatura funkcji:
   int_least32_t trimText(char text[]);

Wazne:
Implementacja ma znajdowac sie w pliku trimming.c, aczkolwiek zalaczajac rozwiazanie prosze rowniez zalaczyc ten plik (trimming.h), jednakze prosze w nim nic nie zmieniac.

Podpowiedzi:
 - Potrzebujemy poznac dlugosc tekstu, prosze znalezc odpowiednia funkcje (nie jest to sizeof!): http://www.cplusplus.com/reference/cstring/
 - Potrzebujemy sprawdzic czy mamy jest cos bialym znakiem, mozna to zrobic recznie, albo skorzystac z gotowca:  http://www.cplusplus.com/reference/cctype/
 - Proszę zwrócić szczególną uwagę na to gdzie zaczynamy, a gdzie kończymy, aby nie wyjsc za zakres tablicy.

Polecam dla wygody:
 Zrobic osobne dwie funkcje:
  - do przycinania od przodu
  - do przycinania od tylu
 a potem obydwie wywolac w funkcji trimText()

Testy:
 - Rozne kombinacje tekstu zaczynajacego lub konczacego sie na biale znaki
 - Tekst pusty ""
 - Tekst zawierajacy wylacznie biale znaki np. " " 
**/

// author: Grzegorz Prowadzacy

#ifndef TRIMMING_H
#define TRIMMING_H

#include <stdint.h>

#ifdef __cplusplus
    extern "C"
    {
#endif
        int_least32_t trimText(char text[]);
#ifdef __cplusplus
    }
#endif

#endif // TRIMMING_H
