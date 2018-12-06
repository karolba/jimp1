/** Panstwa zadaniem jest napisanie funkcji liczacej silnie dla zadanej liczby. Funkcja ma wygladac w nastepujacy sposob:
      T factorian(T value);
    gdzie T jest przezwiskiem typu co najmniej 64-bitowego (szczegoly ponizej).
    Implementacja ma znajdowac sie w pliku factorian.c, aczkolwiek zalaczajac rozwiazanie prosze rowniez zalaczyc ten plik factorian.h, jednakze prosze w nim nic nie zmieniac.

    Wejscie i wyjscie funkcji (przykladowe):
    0   ->  1
    1   ->  1
    5   ->  120
    
    Obsluga bledow:
    1. W razie podania liczby ujemnej funkcja ma zwrocic wartosc ujemna, oraz ustawic odpowiedni kod do zmiennej globalnej errno (http://www.cplusplus.com/reference/cerrno/errno/), jaki kod znajduje sie w enum FactorianErrors.
    2. W razie podania liczby zbyt duzej (ktorej wartosc silni nie zmiesci sie sie w typie T) funkcja ma zwrocic wartosc ujemna, oraz ustawic odpowiedni kod do zmiennej globalnej errno (http://www.cplusplus.com/reference/cerrno/errno/), jaki kod znajduje sie w enum FactorianErrors.

    Podpowiedzi:
    Wyliczanie wartosci za duzej mozna sobie zahardcodowac, aczkolwiek osoby bardziej zaawansowane moga sie zastanowic jak to wyliczac.
**/

#ifndef FACTORIAN_H
#define FACTORIAN_H

#include <stdint.h>


typedef int_fast64_t T;

enum FactorianErrors
{
    FACTORIAN_ERROR_NEGATIVE_VALUE = -1,
    FACTORIAN_TOO_GREAT_VALUE = -2
};


#ifdef __cplusplus
    extern "C"
    {
#endif
        T factorian(T value);
#ifdef __cplusplus
    }
#endif


#endif // FACTORIAN_H
