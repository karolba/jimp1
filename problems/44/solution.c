// author: Karol Baraniecki

#include <stdlib.h>
#include <stdio.h>


#ifndef ForwardList_H
#define ForwardList_H

#include <stddef.h> // size_t
#include <stdint.h> // int_fast32_t
#include <stdbool.h>

/** Tresc zadania: (UWAGA: To bardzo wazne zadanie, w srodku nocy nalezy umiec takie zadania robic!)
Panstwa zadaniem jest napisanie listy jednokrotnie wiązanej, oraz funkcji do jej obslugi. Nasz ForwardList ma zawierać elementy typu T (szczegoly ponizej). Nasza implementacja wzorowana C++owym std::forward_list, aczkolwiek inna niz: http://www.cplusplus.com/reference/forward_list/forward_list/
Jest to lista, skladajaca sie z elementow ForwardList, gdzie kazdy wskazuje na nastepnego.

Ma to byc struktura ForwardList, ktora zawiera w sobie:
    - wartosc w aktualnym wezne (ang. value)
    - wskaznik na nastepny element (ang. next)

Poza struktura ForwardList prosze zaimplementowac pewne funkcje, ktorych deklaracje znajduja sie ponizej.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie list.h, bez robienia w nim jakichkolwiek zmian.

Podpowiedzi:
    - polecam ogarnac operator trojargumentowy: ?:,
    - polecam dopilnowac aby uzyc juz napisanych funkcji wewnatrz innych, zamiast robic to samo np.:
      clear() w destruct(), lub constructLinst1 w constructLinstN() itp.
**/


typedef int_fast32_t T;

#ifdef __cplusplus
    extern "C"
    {
#endif
        struct ForwardList;
        typedef struct ForwardList ForwardList;

        /// Construct and destruct functions:
        // [zaj]funkcja, ktora zwraca ForwardList zaalokowany dynamicznie z wartoscia w pierwszym wezne podana w argumencie:
        ForwardList* constructList(T element);
        // [zaj]funkcja, ktora zwraca ForwardList zaalokowany dynamicznie z okreslona iloscia wezlow zawierajacych wartosc podana w argumencie
        ForwardList* constructListN(size_t elements, T value);

        // [zaj]funkcja, ktora usuwa cala liste wierzcholkow ForwardLista zwalniajac przy tym pamiec zaalokowana przez l
        void destruct(ForwardList* l);

        // funkcja, ktora kopiuje nasz ForwardList i jego elementy (gleboka kopia), podobnie jak C++owy http://www.cplusplus.com/reference/forward_list/forward_list/operator=/
        ForwardList* cloneList(const ForwardList* l);

        // [zaj]funkcja, ktora zwalnia pamiec calej ForwardList, zostawiajac nasza liste w takim stanie jak po zawolaniu: constructList(0);
        void clear(ForwardList* l);


        /// Comfort functions:
        // funkcja zwraca N-ty wezel z ForwardList, a jesli nie ma takowego NULL, takiej funkcji nie ma w std::forward_list:
        ForwardList* getNode(ForwardList* l, size_t index);
        // [zaj]funkcja zwraca wartosc danego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
        T get(const ForwardList* l);
        // funkcja ustawia wartosc danego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
        void setNodeValue(ForwardList* l, T value);
        // [zaj]funkcja zwraca wskaznik do kolejnego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
        ForwardList* nextNode(const ForwardList* l);


        /// Capasity functions:
        // [zaj]funkcja zwraca ilosc elementow ForwardLista, co prawda std::forward_list nie zawiera tej metody ze wzgledu na jej nieoptymalnosc
        size_t size(const ForwardList* l);
        // funkcja ustawiajaca zadana ilosc elementow ForwardLista, jesli zmniejszamy zostaja obciete ostatnie elementy, jesli zwiekszamy nowe elementy beda mialy wartosc 0, zupelnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/resize/
        void resize(ForwardList* l, size_t newSize);
//        // funkcja zwraca true jesli ForwardList nie zawiera elementow, zupelnie jak: // http://www.cplusplus.com/reference/ForwardList/ForwardList/empty/
//        bool empty(const ForwardList* l);


        ///  Element access function:
        // [zaj]funkcja zwraca wskaznik do wartosci elementu z ForwardList o zadanym indeksie, w razie wyjscia poza tablice zwraca NULL, oczywiscie std::forward_list nie zawiera takiej metody ze wzgledu na jej nieoptymalnosc
        T* at(ForwardList* l, size_t index);
        // [zaj]zwraca wskaznik do wartosci pierwszego element ForwardLista, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/front/
        T* front(ForwardList* l);
        // [zaj]zwraca wskaznik do wartosci ostatniego element listy, oczywiscie std::forward_list nie zawiera takiej metody ze wzgledu na jej nieoptymalnosc:
        T* back(ForwardList* l);


        ///  Modifiers:
        // [zaj]funkcja wrzucajaca element na poczatek ForwardLista, a nastepnie zwraca liste zaczynajaca sie od wstawionego elementu, podobnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/push_front/
        ForwardList* push_front(ForwardList* l, T element);
        // [zaj]funkcja usuwajaca element z poczatku ForwardLista, a nastepnie zwraca liste od drugiego elementu, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/pop_front/
        ForwardList* pop_front(ForwardList* l);

        // [zaj]funkcja zamiast dotychczasowego kontekstu w liscie ustawia tablice elementow, podobnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/assign/
        void assign(ForwardList* l, size_t elementCount, const T elements[]);

        // funkcja usuwajaca element z ForwardLista o zadanym indeksie, zwracajaca wezel tuz za usunietym elementem, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/erase_after/
        ForwardList* erase_after(ForwardList* l, size_t index);
        // funkcja wstawiajaca dany element na pozycje o wskazanym indeksie przesuwajac nastepne elementy w prawo zwracajaca pozycje wstawienia elementu, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/insert_after/
        ForwardList* insert_after(ForwardList* l, size_t index, T element);


        /// Operations:
        // funkcja, ktora zwroci nasza liste po odwroceniu kolejnosci jej elementow, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/reverse/
        ForwardList* reverse(ForwardList* l);
        // funkcja, ktora zwroci nasza liste z posortowanymi elementami, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/sort/
        ForwardList* sort(ForwardList* l);
        // funkcja, ktora polecam zaimplementowac (ale testy tego nie sprawdza), ktora wyswietli nasza liste, polecam pythoniczna forme
        void printList(ForwardList* l);


        /// Functions to cooperate with function pointers:
        // [zaj]funkcja, ktora dla kazdego elementu listy zawola funkcje przekazana jako argument:
        void for_each(ForwardList* l, void(*f)(ForwardList* current));
        // funkcja, ktora usunie z listy wszystkie elementy, dla ktorych wartosc z funkcji przekazanej jako argument zwroci true, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/remove_if/
        ForwardList* remove_if(ForwardList* l, bool(*predicate)(ForwardList* current));

        /** inne, fajne funkcje ForwardLista dla ambitnych, na ktore nie dostarczylem testow:
         http://www.cplusplus.com/reference/forward_list/forward_list/splice_after/
         http://www.cplusplus.com/reference/forward_list/forward_list/remove/
         http://www.cplusplus.com/reference/forward_list/forward_list/unique/
         http://www.cplusplus.com/reference/forward_list/forward_list/merge/ **/

#ifdef __cplusplus
    }
#endif

#endif // ForwardList_H



struct ForwardList {
    T value;
    ForwardList *next;  
};

/// Construct and destruct functions:
// funkcja, ktora zwraca ForwardList zaalokowany dynamicznie z wartoscia w pierwszym wezne podana w argumencie:
ForwardList* constructList(T element) {
    ForwardList *list = (ForwardList *) malloc(sizeof(ForwardList));
    list->value = element;
    list->next = NULL;

    return list;
}


// funkcja, ktora zwraca ForwardList zaalokowany dynamicznie z okreslona iloscia wezlow zawierajacych wartosc podana w argumencie
ForwardList* constructListN(size_t elements, T value) {
    ForwardList *first = constructList(value);
    ForwardList *last = first;
    for(size_t i = 1; i < elements; i++) {
        last->next = constructList(value);
        last = last->next;
    }
    return first;
}

// funkcja, ktora usuwa cala liste wierzcholkow ForwardLista zwalniajac przy tym pamiec zaalokowana przez l
void destruct(ForwardList* l) {
    do {
        ForwardList *current = l;
        l = l->next;
        free(current);
    } while(l != NULL);
}

// funkcja, ktora kopiuje nasz ForwardList i jego elementy (gleboka kopia), podobnie jak C++owy http://www.cplusplus.com/reference/forward_list/forward_list/operator=/
ForwardList* cloneList(const ForwardList* l) {
}

// funkcja, ktora zwalnia pamiec calej ForwardList, zostawiajac nasza liste w takim stanie jak po zawolaniu: constructList();
void clear(ForwardList* l) {
    ForwardList *next = l;
    do {
        ForwardList *current = next;
        next = l->next;
        if(l != next)
            free(current);
    } while(next != NULL);
}


/// Comfort functions:
// funkcja zwraca N-ty wezel z ForwardList, a jesli nie ma takowego NULL, takiej funkcji nie ma w std::forward_list:
ForwardList* getNode(ForwardList* l, size_t index) {
    while(index--) {
        if(l->next == NULL)
            break;
        l = l->next;
    }
    return l;
}
// funkcja zwraca wartosc danego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
T get(const ForwardList* l) {
    return l->value;
}
// funkcja ustawia wartosc danego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
void setNodeValue(ForwardList* l, T value) {
    l->value = value;
}

// funkcja zwraca wskaznik do kolejnego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
ForwardList* nextNode(const ForwardList* l) {
    return l->next;
}


/// Capasity functions:
// funkcja zwraca ilosc elementow ForwardLista, co prawda std::forward_list nie zawiera tej metody ze wzgledu na jej nieoptymalnosc
size_t size(const ForwardList* l) {
    size_t s = 1;

    while(l->next != NULL) {
        l = l->next;
        s++;
    }

    return s;
}
// funkcja ustawiajaca zadana ilosc elementow ForwardLista, jesli zmniejszamy zostaja obciete ostatnie elementy, jesli zwiekszamy nowe elementy beda mialy wartosc 0, zupelnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/resize/
void resize(ForwardList* l, size_t newSize);
//        // funkcja zwraca true jesli ForwardList nie zawiera elementow, zupelnie jak: // http://www.cplusplus.com/reference/ForwardList/ForwardList/empty/
//        bool empty(const ForwardList* l);


///  Element access function:
// funkcja zwraca wskaznik do wartosci elementu z ForwardList o zadanym indeksie, w razie wyjscia poza tablice zwraca NULL, oczywiscie std::forward_list nie zawiera takiej metody ze wzgledu na jej nieoptymalnosc
T* at(ForwardList* l, size_t index) {
    while(index--) {
        if(l->next == NULL)
            return NULL;
        l = l->next;
    }
    return &l->value;
}
// zwraca wskaznik do wartosci pierwszego element ForwardLista, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/front/
T* front(ForwardList* l) {
    return &l->value;
}
// zwraca wskaznik do wartosci ostatniego element listy, oczywiscie std::forward_list nie zawiera takiej metody ze wzgledu na jej nieoptymalnosc:
T* back(ForwardList* l) {
    while(l->next != NULL) {
        l = l->next;
    }
    return &l->value;
}


///  Modifiers:
// funkcja wrzucajaca element na poczatek ForwardLista, a nastepnie zwraca liste zaczynajaca sie od wstawionego elementu, podobnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/push_front/
ForwardList* push_front(ForwardList* l, T element) {
    ForwardList *first = constructList(element);
    first->next = l;
    return first;
}

// funkcja usuwajaca element z poczatku ForwardLista, a nastepnie zwraca liste od drugiego elementu, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/pop_front/
ForwardList* pop_front(ForwardList* l) {
    ForwardList *n = l->next;
    free(l);
    return n;
}

// funkcja zamiast dotychczasowego kontekstu w liscie ustawia tablice elementow, podobnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/assign/
void assign(ForwardList* l, size_t elementCount, const T elements[]) {
    if(l->next != NULL)
        destruct(l->next);
    l->next = constructListN(elementCount - 1, 0);
    l->value = elements[0];
    for(int i = 1; i < elementCount; i++) {
        l = l->next;
        l->value = elements[i];
    }
}

// funkcja usuwajaca element z ForwardLista o zadanym indeksie, zwracajaca wezel tuz za usunietym elementem, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/erase_after/
ForwardList* erase_after(ForwardList* l, size_t index) {}
// funkcja wstawiajaca dany element na pozycje o wskazanym indeksie przesuwajac nastepne elementy w prawo zwracajaca pozycje wstawienia elementu, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/insert_after/
ForwardList* insert_after(ForwardList* l, size_t index, T element){}


/// Operations:
// funkcja, ktora zwroci nasza liste po odwroceniu kolejnosci jej elementow, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/reverse/
ForwardList* reverse(ForwardList* l){}
// funkcja, ktora zwroci nasza liste z posortowanymi elementami, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/sort/
ForwardList* sort(ForwardList* l){}
// funkcja, ktora polecam zaimplementowac (ale testy tego nie sprawdza), ktora wyswietli nasza liste, polecam pythoniczna forme
void printList(ForwardList* l){}


/// Functions to cooperate with function pointers:
// funccja, ktora dla kazdego elementu listy zawola funkcje przekazana jako argument:
void for_each(ForwardList* l, void(*f)(ForwardList* current))
{
    do {
        f(l);
        l = l->next;
    } while(l != NULL);
}
// funkcja, ktora usunie z listy wszystkie elementy, dla ktorych wartosc z funkcji przekazanej jako argument zwroci true, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/remove_if/
ForwardList* remove_if(ForwardList* l, bool(*predicate)(ForwardList* current)){}
