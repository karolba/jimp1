// author: Karol Baraniecki

#include <stdlib.h>


/************************ vector.h ********************/

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // size_t
#include <stdint.h> // int_fast32_t
#include <stdbool.h>

/** Tresc zadania: (UWAGA: To bardzo wazne zadanie, w srodku nocy nalezy umiec takie zadania robic!)
Panstwa zadaniem jest napisanie automatycznie rozszerzajacej sie tablicy dynamicznej (zwanej potocznie Vector), oraz funkcji do jej obslugi. Nasz Vector ma byc tablica elementow typu T (szczegoly ponizej). Nasza implementacja wzorowana C++owym std::vector, aczkolwiek inna: http://www.cplusplus.com/reference/vector/vector/

Nasza implementacja w razie automatycznego zwiekszania rozmiaru ma allokowac pamiec tylko o 1 wieksza!
Ma to byc struktura Vector, ktora zawiera w sobie:
    - wskaznik na tablice dynamiczna (ang. data)
    - rozmiar aktualnie zaalokowanej tablicy dynamicznej (ang. capacity)
    - ilosc elementow w tablicy (ang. size)

Poza struktura Vector prosze zaimplementowac pewne funkcje, ktorych deklaracje znajduja sie ponizej.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie vector.h, bez robienia w nim jakichkolwiek zmian.

Podpowiedzi:
    - polecam ogarnac operator trojargumentowy: ?:,
    - polecam ogarnac funkcje realloc()
**/


typedef int_fast32_t T;

#ifdef __cplusplus
    extern "C"
    {
#endif
        struct Vector;
        typedef struct Vector Vector;

        /// Construct and destruct functions
        // funkcja, ktora zwraca pusty Vector zaalokowany dynamicznie (wszystkie skladowe sa na poczatku zero).
        Vector* constructVector(void);
        // funkcja, ktora zwalnia zaalokowana pamiec na elementy vectora i ustawia size i capacity w vectorze na 0, funkcja nie robi free(v)
        void destruct(Vector* v);
        // funkcja, ktora kopiuje nasz Vector i jego elementy (gleboka kopia), podobnie jak C++owy http://www.cplusplus.com/reference/vector/vector/operator=/
        Vector* cloneVector(const Vector* v);


        /// Capasity functions:
        // funkcja zwraca ilosc elementow vectora, zupelnie jak: www.cplusplus.com/reference/vector/vector/size/
        size_t size(const Vector* v);
        // funkcja ustawiajaca zadana ilosc elementow vectora, jesli zmniejszamy zostaja obciete ostatnie elementy, jesli zwiekszamy nowe elementy beda mialy wartosc 0, zupelnie jak: www.cplusplus.com/reference/vector/vector/resize/
        void resize(Vector* v, size_t newSize);
        // funkcja zwraca ilosc elementow jaki na chwile obecna moze pomiescic vector bez reallokacji, zupelnie jak: www.cplusplus.com/reference/vector/vector/capacity/
        size_t capacity(const Vector* v);
        // funkcja zwraca true jesli vector nie zawiera elementow, zupelnie jak: // http://www.cplusplus.com/reference/vector/vector/empty/
        bool empty(const Vector* v);
        // dla zadanego rozmiaru wiekszego niz aktualnie zajmowany przez elementy vectora zostaje allokowana przestrzen na nowe elementy, zupelnie jak http://www.cplusplus.com/reference/vector/vector/reserve/
        bool reserve(Vector* v, size_t size);


        ///  Element access function:
        // funkcja zwraca wskaznik do elementu Vectora o zadanym indeksie, w razie wyjscia poza tablice zwraca NULL, podobna do: http://www.cplusplus.com/reference/vector/vector/at/
        T* at(Vector* v, size_t index);
        // zwraca wskaznik na pierwszy element Vectora, podobna do: http://www.cplusplus.com/reference/vector/vector/front/
        T* front(Vector* v);
        // jw. ale na ostatni element Vectora, podobna do: www.cplusplus.com/reference/vector/vector/back/
        T* back(Vector* v);


        ///  Modifiers:
        // funkcja wrzucajaca element na koniec Vectora, a jesli nie ma na nim miejsca dokonujaca automatycznej reallokacji, podobna do: http://www.cplusplus.com/reference/vector/vector/push_back/
        void push_back(Vector* v, T element);
        // funkcja usuwajaca element z konca Vectora, przy pustym Vectorze nic nie robi, podobna do: http://www.cplusplus.com/reference/vector/vector/push_back/
        void pop_back(Vector* v);

        // funkcja usuwajaca element z Vectora o zadanym indeksie, zwracajaca pozycje tuz za usunietym elementem, podobna do: http://www.cplusplus.com/reference/vector/vector/erase/
        T* erase(Vector* v, size_t index);
        // funkcja wstawiajaca dany element na pozycje o wskazanym elemencie przesuwajac nastepne elementy w prawo zwracajaca pozycje wstawienia elementu, podobna do: http://www.cplusplus.com/reference/vector/vector/insert/
        T* insert(Vector* v, T element, size_t index);

        /** inne, fajne funkcje vectora dla ambitnych, na ktore nie dostarczylem testow:
            http://www.cplusplus.com/reference/vector/vector/begin/
            http://www.cplusplus.com/reference/vector/vector/end/
            http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/
            http://www.cplusplus.com/reference/vector/vector/data/
            http://www.cplusplus.com/reference/vector/vector/swap/
            http://www.cplusplus.com/reference/vector/vector/assign/ **/
#ifdef __cplusplus
    }
#endif

#endif // VECTOR_H



/************************ vector.c ********************/


struct Vector {
    size_t m_size;
    size_t m_capacity;
    T *m_data;
};

Vector * constructVector(void) {
    Vector *v = (Vector *) malloc(sizeof(Vector));
    v->m_size = 0;
    v->m_capacity = 0;
    v->m_data = NULL;
    reserve(v, 0);
    return v;
}

void destruct(Vector *v) {
    free(v->m_data);

    v->m_size = 0;
    v->m_capacity = 0;
    v->m_data = NULL;
    // free(v);
}

Vector* cloneVector(const Vector *v) {
    size_t len = size(v);

    Vector *other = constructVector();
    resize(other, len);

    for(size_t i = 0; i < len; i++) {
        other->m_data[i] = v->m_data[i];
    }

    return other;
}

size_t size(const Vector *v) {
    return v->m_size;
}

void resize(Vector *v, size_t newSize) {
    size_t oldSize = size(v);
    reserve(v, newSize);
    for(size_t i = oldSize; i < newSize; i++) {
        v->m_data[i] = 0;
    }
    v->m_size = newSize;
}

size_t capacity(const Vector* v) {
    return v->m_capacity;
}

bool empty(const Vector* v) {
    return size(v) == 0;
}

bool reserve(Vector *v, size_t sz) {
    if(sz <= capacity(v))
        return false;

    v->m_data = (T *) realloc(v->m_data, sizeof(T) * sz);

    v->m_capacity = sz;
    
    return true;
}

T * at(Vector *v, size_t index) {
    if(index >= size(v))
        return NULL;

    return &v->m_data[index];
}

T * front(Vector *v) {
    return at(v, 0);
}

T * back(Vector *v) {
    return at(v, size(v) - 1); // leveraging defined unsigned overflow
}

void push_back(Vector *v, T element) {
    resize(v, size(v) + 1);
    v->m_data[size(v) - 1] = element;
}

void pop_back(Vector *v) {
    if(!empty(v))
        resize(v, size(v) - 1);
}

T * erase(Vector *v, size_t index) {
    size_t sz = size(v);

    if(index >= sz)
        return NULL;
    
    v->m_size -= 1;

    for(size_t i = index; i < sz - 1; i++) {
        v->m_data[i] = v->m_data[i + 1];
    }

    return &v->m_data[index];
}

T * insert(Vector *v, T element, size_t index) {
    resize(v, size(v) + 1);

    for(size_t i = size(v) - 1; i > index; i--) {
        v->m_data[i] = v->m_data[i - 1];
    }
    
    v->m_data[index] = element;    

    return &v->m_data[index];
}

