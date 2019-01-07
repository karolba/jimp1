// author: Karol Baraniecki

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "problem.h"

#define D(l) printf("%s: ", __PRETTY_FUNCTION__); printList(l);

struct ForwardList {
    T value;

    ForwardList *next;
};

/// Construct and destruct functions:
// [zaj]funkcja, ktora zwraca ForwardList zaalokowany dynamicznie z wartoscia w pierwszym wezne podana w argumencie:
ForwardList *constructList(T element) {
    ForwardList *list = (ForwardList *) malloc(sizeof(ForwardList));
    list->value = element;
    list->next = NULL;
    return list;
}

// [zaj]funkcja, ktora zwraca ForwardList zaalokowany dynamicznie z okreslona iloscia wezlow zawierajacych wartosc podana w argumencie
ForwardList *constructListN(size_t elements, T value) {
    ForwardList *first = constructList(value);
    ForwardList *last = first;
    for(int i = 1; i < elements; i++) {
        ForwardList *current = constructList(value);
        last->next = current;
        last = current;
    }
    D(first)
    return first;
}

// [zaj]funkcja, ktora usuwa cala liste wierzcholkow ForwardLista zwalniajac przy tym pamiec zaalokowana przez l
void destruct(ForwardList *l) {
    while(l->next != NULL) {
        ForwardList *prev = l;
        l = l->next;
        free(prev);
    }
    free(l);
}

// funkcja, ktora kopiuje nasz ForwardList i jego elementy (gleboka kopia), podobnie jak C++owy http://www.cplusplus.com/reference/forward_list/forward_list/operator=/
ForwardList *cloneList(const ForwardList *l) {
    D(l)
    ForwardList *copy = constructList(l->value);
    ForwardList *copyFirst = copy;
    while(l->next != NULL) {
        l = l->next;
        copy->next = constructList(l->value);
        copy = copy->next;
    }
    D(copyFirst)
    return copyFirst;
}

// [zaj]funkcja, ktora zwalnia pamiec calej ForwardList, zostawiajac nasza liste w takim stanie jak po zawolaniu: constructList(0);
void clear(ForwardList *l) {
    destruct(l->next);
    l->next = NULL;
    l->value = 0;
}


/// Comfort functions:
// funkcja zwraca N-ty wezel z ForwardList, a jesli nie ma takowego NULL, takiej funkcji nie ma w std::forward_list:
ForwardList *getNode(ForwardList *l, size_t index) {
    while(index--) {
        if(l->next == NULL)
            return NULL;
        l = l->next;
    }
    return l;
}
// [zaj]funkcja zwraca wartosc danego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
T get(const ForwardList *l) {
    return l->value;
}
// [zaj]funkcja ustawia wartosc danego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
void setNodeValue(ForwardList *l, T value) {
    l->value = value;
}
// [zaj]funkcja zwraca wskaznik do kolejnego wezla, mamy taka funkcje aby nie grzebac po bebechach naszego ForwardList, takiej funkcji nie ma w std::forward_list:
ForwardList *nextNode(const ForwardList *l) {
    return l->next;
}


/// Capasity functions:
// [zaj]funkcja zwraca ilosc elementow ForwardLista, co prawda std::forward_list nie zawiera tej metody ze wzgledu na jej nieoptymalnosc
size_t size(const ForwardList *l) {
    size_t sz = 0;
    while(l != NULL) {
        sz++;
        l = l->next;
    }
    return sz; // ??
}

static ForwardList *backList(ForwardList *l) {
    while(l->next != NULL) {
        l = l->next;
    }
    return l;
}

// 'a' <-> 'b' <-> 'c'
//  0       1       2
// funkcja ustawiajaca zadana ilosc elementow ForwardLista, jesli zmniejszamy zostaja obciete ostatnie elementy, jesli zwiekszamy nowe elementy beda mialy wartosc 0, zupelnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/resize/
void resize(ForwardList *l, size_t newSize) {
    size_t sz = size(l) + 1;
    if(newSize < sz) {
        l = getNode(l, newSize);
        destruct(l->next);
        l->next = NULL;
    } else if(newSize > sz) {
        l = backList(l);
        l->next = constructListN(0, newSize - sz);
    }
}
//        // funkcja zwraca true jesli ForwardList nie zawiera elementow, zupelnie jak: // http://www.cplusplus.com/reference/ForwardList/ForwardList/empty/
//        bool empty(const ForwardList *l); - ta funkcja u nas zawsze bedzie true, wiec nie ma sensu


///  Element access function:
// [zaj]funkcja zwraca wskaznik do wartosci elementu z ForwardList o zadanym indeksie, w razie wyjscia poza tablice zwraca NULL, oczywiscie std::forward_list nie zawiera takiej metody ze wzgledu na jej nieoptymalnosc
T *at(ForwardList *l, size_t index) {
    l = getNode(l, index);
    return l == NULL ? NULL : &l->value;
}
// [zaj]zwraca wskaznik do wartosci pierwszego element ForwardLista, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/front/
T *front(ForwardList *l) {
    return &l->value;
}
// [zaj]zwraca wskaznik do wartosci ostatniego element listy, oczywiscie std::forward_list nie zawiera takiej metody ze wzgledu na jej nieoptymalnosc:
T *back(ForwardList *l) {
    while(l->next != NULL) {
        l = l->next;
    }
    return &l->value;
}


///  Modifiers:
// [zaj]funkcja wrzucajaca element na poczatek ForwardLista, a nastepnie zwraca liste zaczynajaca sie od wstawionego elementu, podobnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/push_front/
ForwardList *push_front(ForwardList *l, T element) {
    D(l)
    ForwardList *new_second = constructList(l->value);
    new_second->next = l->next;
    l->next = new_second;
    l->value = element;
    D(l)
    return l;
}

// [zaj]funkcja usuwajaca element z poczatku ForwardLista, a nastepnie zwraca liste od drugiego elementu, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/pop_front/
ForwardList *pop_front(ForwardList *l) {
    ForwardList *next = l->next;
    l->next = NULL;
    destruct(l);
    return next;
}

// [zaj]funkcja zamiast dotychczasowego kontekstu w liscie ustawia tablice elementow, podobnie jak: http://www.cplusplus.com/reference/forward_list/forward_list/assign/
void assign(ForwardList *l, size_t elementCount, const T elements[]) {
    l->value = elements[0];
    for(size_t i = 1; i < elementCount; i++) {
        if(l->next == NULL) {
            l->next = constructList(elements[i]);
        } else {
            l->next->value = elements[i];
        }
        l = l->next;
    }
}

// funkcja usuwajaca element z ForwardLista o zadanym indeksie, zwracajaca wezel tuz za usunietym elementem, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/erase_after/
ForwardList *erase_after(ForwardList *l, size_t index) {
    D(l)
    if(index == 0)
        return pop_front(l);

    ForwardList *node = getNode(l, index);
    if(node == NULL || node->next == NULL)
        return NULL;

    ForwardList *erased = node->next;
    node->next = erased->next;
    
    erased->next = NULL;
    destruct(erased);
    D(l)
    
    return node->next;
}

// funkcja wstawiajaca dany element na pozycje o wskazanym indeksie przesuwajac nastepne elementy w prawo zwracajaca pozycje wstawienia elementu, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/insert_after/
ForwardList *insert_after(ForwardList *l, size_t index, T element) {
    // TODO
}


/// Operations:
// funkcja, ktora zwroci nasza liste po odwroceniu kolejnosci jej elementow (ale bez wykonywania glebokiej kopii listy), podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/reverse/
ForwardList *reverse(ForwardList *l) {
    ForwardList *newEnd = NULL;
    
    while(l->next != NULL) {
        ForwardList *oldNext = l->next;
        l->next = newEnd;
        newEnd = l;
        l = oldNext;
    }
    return l;
}
// funkcja, ktora zwroci nasza liste z posortowanymi elementami, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/sort/
ForwardList *sort(ForwardList *l) {
    // TODO
}
// funkcja, ktora polecam zaimplementowac (ale testy tego nie sprawdza), ktora wyswietli nasza liste, polecam pythoniczna forme

void printList(const ForwardList *l) {
    printf("[");
    bool first = true;
    while(l != NULL) {
        if(!first)
            printf(",");
        first = false;

        printf(" %d", (int) l->value);
        l = l->next;
    }
    printf(" ]\n");
}
// funkcja, ktora usunie duplikaty z naszej listy, UWAGA: zakladajac, ze lista jest posortowana, podobnie do: http://www.cplusplus.com/reference/forward_list/forward_list/unique/
ForwardList *unique(ForwardList *l) {
    // TODO
}


/// Functions to cooperate with function pointers:
// [zaj]funkcja, ktora dla kazdego elementu listy zawola funkcje przekazana jako argument:
void for_each(ForwardList *l, void(*f)(ForwardList *current)) {
    while(l != NULL) {
        f(l);
        l = l->next;
    }
}
// funkcja, ktora usunie z listy wszystkie elementy, dla ktorych wartosc z funkcji przekazanej jako argument zwroci true, podobna do: http://www.cplusplus.com/reference/forward_list/forward_list/remove_if/
ForwardList *remove_if(ForwardList *l, bool(*predicate)(T nodeValue)) {
    // TODO
}
