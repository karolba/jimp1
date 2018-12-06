// author: Karol Baraniecki

#include <stdio.h>
#include <stdlib.h>


#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h> // size_t
#include <stdint.h> // int_fast32_t
#include <stdbool.h> // true, false, bool

/** Tresc zadania: (UWAGA: To bardzo wazne zadanie, w srodku nocy nalezy umiec takie zadania robic!)
Panstwa zadaniem jest napisanie tablicy, ktora w momencie inicjalizacji ma ustawiony rozmiar, ktory pamieta (Array), oraz funkcji do jej obslugi.
Nasza implementacja jest poniekąd wzorowana na C++owej std::array: http://www.cplusplus.com/reference/array/array/ , ale nie implementujemy jej dokladnie.
Ma to byc struktura Array, ktora zawiera w sobie:
    - wskaznik na tablice dynamiczna (np. z ang. data)
    - rozmiar tablicy (ang. size)

Poza struktura Array prosze zaimplementowac pewne funkcje, ktorych deklaracje i opisy znajduja sie ponizej.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie Array.h, bez robienia w nim jakichkolwiek zmian.

Podpowiedzi:
    - polecam ogarnac operator trojargumentowy: ?:,
    - polecam ogarnac funkcje calloc()
**/


typedef int_fast32_t T;

#ifdef __cplusplus
    extern "C"
    {
#endif
        struct Array;
        typedef struct Array Array;

        /// Costruction and destruction functions:
        // funkcja, ktora zwraca Array zaalokowany dynamicznie, z zaalokowana tablica dla zadanego rozmiaru, wartosci elementow tablicy maja byc zerowane
        Array* constructArray(size_t size);
        // funkcja, ktora zwalnia zaalokowana pamiec na elementy Arraya i ustawia size i date w Array'u odpowiednio na 0 i NULL
        void destruct(Array* array);

        /// Capasity:
        // funkcja zwraca ilosc elementow Arraya, zupelnie jak: http://www.cplusplus.com/reference/array/array/size/
        size_t size(const Array* array);
        // funkcja zwracajaca true jesli mamy do czynienia z pustym Array, zupelnie jak: http://www.cplusplus.com/reference/array/array/empty/
        bool empty(const Array* array);

        ///  Element access functions:
        // funkcja zwraca wskaznik do elementu Array'a o zadanym indeksie, w razie wyjscia poza tablice zwraca NULL, podobna do: http://www.cplusplus.com/reference/array/array/at/
        T* at(Array* array, size_t index);
        // zwraca wskaznik na pierwszy element Array'a, podobna do: http://www.cplusplus.com/reference/array/array/front/
        T* front(Array* array);
        // jw. ale na ostatni element Array'a, podobna do: www.cplusplus.com/reference/array/array/back/
        T* back(Array* array);
        // zwraca wskaznik do wewnetrznej tablicy Array'a, podobnie do: http://www.cplusplus.com/reference/array/array/data/
        const T* data(Array* array);

        ///  Modifiers functions:
        // ustawia wszystkim elementom tablicy zadana wartosc, podobnie do: http://www.cplusplus.com/reference/array/array/fill/
        void fill(Array* array, T value);
        // funkcja kopiuje wartosci tablicy na nasze Array, rozmiary tablicy i Array sie zgadzaja
        void assign(Array* array, const T tab[], size_t tabSize);
        // funkcja reorganizujaca elementy wg zasady "Ci co pierwsi beda ostatnimi, a ci co ostatni pierwszymi"
        void reverse(Array* array);

        /// Optional functions: (tych funkcji nie musza Panstwo implementowac, ale ambitni moga). Pplecam aby funkcje generowaly tekst w formacie:
        /// array(3) = {1, 2, 3}
        char* toText(Array* array);
        void print(Array* array);
        // funkcja wykonujaca gleboka kopie naszego Array wraz z jego elementami:
        Array* cloneArray(const Array* array);

#ifdef __cplusplus
    }
#endif

#endif // ARRAY_H









struct Array {
    size_t len;
    T *data;
};

/// Costruction and destruction functions:
// funkcja, ktora zwraca Array zaalokowany dynamicznie, z zaalokowana tablica dla zadanego rozmiaru, wartosci elementow tablicy maja byc zerowane
Array *constructArray(size_t size) {
    Array *a = (Array *) malloc(sizeof(Array));
    a->len = size;
    a->data = (T *) malloc(sizeof(T) * size);
}

// funkcja, ktora zwalnia zaalokowana pamiec na elementy Arraya i ustawia size i date w Array'u odpowiednio na 0 i NULL
void destruct(Array *array) {
    free(array->data);
    array->len = 0;
    array->data = NULL;
}

/// Capasity:
// funkcja zwraca ilosc elementow Arraya, zupelnie jak: http://www.cplusplus.com/reference/array/array/size/
size_t size(const Array *array) {
    return array->len;
}

// funkcja zwracajaca true jesli mamy do czynienia z pustym Array, zupelnie jak: http://www.cplusplus.com/reference/array/array/empty/
bool empty(const Array *array) {
    return array->len == 0;
}

///  Element access functions:
// funkcja zwraca wskaznik do elementu Array'a o zadanym indeksie, w razie wyjscia poza tablice zwraca NULL, podobna do: http://www.cplusplus.com/reference/array/array/at/
T *at(Array *array, size_t index) {
    return (index >= array->len) ? NULL : &array->data[index];
}

// zwraca wskaznik na pierwszy element Array'a, podobna do: http://www.cplusplus.com/reference/array/array/front/
T *front(Array *array) {
    return &array->data[0];
}
// jw. ale na ostatni element Array'a, podobna do: www.cplusplus.com/reference/array/array/back/
T *back(Array *array) {
    return &array->data[array->len - 1];
}
// zwraca wskaznik do wewnetrznej tablicy Array'a, podobnie do: http://www.cplusplus.com/reference/array/array/data/
const T *data(Array *array) {
    return array->data;
}

///  Modifiers functions:
// ustawia wszystkim elementom tablicy zadana wartosc, podobnie do: http://www.cplusplus.com/reference/array/array/fill/
void fill(Array *array, T value) {
    for(size_t i = 0; i < array->len; i++) {
        array->data[i] = value;
    }
}
// funkcja kopiuje wartosci tablicy na nasze Array, rozmiary tablicy i Array sie zgadzaja
void assign(Array *array, const T tab[], size_t tabSize) {
    for(size_t i = 0; i < tabSize; i++) {
        array->data[i] = tab[i];
    }
}

static void swap(Array *a, size_t i1, size_t i2) {
    T tmp = a->data[i2];
    a->data[i2] = a->data[i1];
    a->data[i1] = tmp;
}

// funkcja reorganizujaca elementy wg zasady "Ci co pierwsi beda ostatnimi, a ci co ostatni pierwszymi"
void reverse(Array *array) {
    for(size_t i = 0; i < array->len / 2; i++) {
        swap(array, i, array->len - i - 1);
    }
}

/// Optional functions: (tych funkcji nie musza Panstwo implementowac, ale ambitni moga). Pplecam aby funkcje generowaly tekst w formacie:
/// array(3) = {1, 2, 3}
char *toText(Array *array);
void print(Array *array);
// funkcja wykonujaca gleboka kopie naszego Array wraz z jego elementami:
Array *cloneArray(const Array *array);
