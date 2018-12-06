// author: Karol Baraniecki

/************* basename.h ****************/
#ifndef BASENAME_H
#define BASENAME_H

/**
Tresc zadania:
Panstwa zadaniem jest napisanie funkcji baseName(), ktora dla podanej sciezki pliku zwroci nazwe:
1) nie zawierajaca rozszerzenia
2) nie zawierajaca sciezki do pliku
3) funkcja ma zwrocic odpowiednia wartosc ze zbioru ponizej

Polecam przejrzec funkcje z http://www.cplusplus.com/reference/cstring/ i wybrac sobie cos do uzycia.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie basename.h, bez robienia w nim jakichkolwiek zmian.

Polecam dla wygody:
- Zrobic osobne funkcje do przycinania od przodu i przycinania od typu
**/

enum FileNameInfo
{
    FILE_NAME_NOT_CHANGED       = 0x00,
    FILE_NAME_REMOVED_EXTENTION = 0x01,
    FILE_NAME_REMOVED_PATH      = 0x02,
    FILE_NAME_REMOVED_EXTENTION_AND_PATH = FILE_NAME_REMOVED_EXTENTION + FILE_NAME_REMOVED_PATH
};

#ifdef __STDC__
    typedef enum FileNameInfo FileNameInfo;
#endif


#ifdef __cplusplus
    extern "C"
    {
#endif
        FileNameInfo baseName(const char filePath[], char fileBaseName[]);
#ifdef __cplusplus
    }
#endif


#ifdef _WIN32
    const char PATH_SEPARATOR = '\\';
#elif __linux__ 
    const char PATH_SEPARATOR = '/';
#else
    #error "Unsupported Operation System!"
#endif


#endif // BASENAME_H

/************* basename.h ****************/

#include <string.h>

FileNameInfo baseName(const char filePath[], char fileBaseName[]) {
    size_t start = 0;
    size_t stop = 0;
    
    size_t len = strlen(filePath);

    // C++ doesn't like |= on enums
    int removed = FILE_NAME_NOT_CHANGED;

    for(size_t i = 0; i < len; i++) {
        if(filePath[i] == '/') {
            removed |= FILE_NAME_REMOVED_PATH;
            start = i + 1;
        }
        if(filePath[i] == '.') {
            removed |= FILE_NAME_REMOVED_EXTENTION;
            stop = len - i;
        }
    }

    memcpy(fileBaseName, filePath + start, len - start - stop);

    return (FileNameInfo) removed;
}
