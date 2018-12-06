// author: Karol Baraniecki

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "trimming.h"

int_least32_t trimRight(char *text) {
    int_least32_t trimmed = 0;
    
    size_t s = strlen(text);

    while(s > 0 && isspace(text[--s])) {
        trimmed++;
        text[s] = '\0';
    }

    return trimmed;
}

int_least32_t trimLeft(char *text) {
    int_least32_t toTrim = 0;
    size_t size = strlen(text);
    
    for(size_t i = 0; i < size; i++) {
        if(! isspace(text[i]))
            break;
        toTrim++;
    }

    if(toTrim == 0)
        return 0;

    for(size_t i = 0; i < size - toTrim; i++) {
        text[i] = text[i + toTrim];
    }

    for(size_t i = size - toTrim; i < size; i++) {
        text[i] = '\0';
    }

    return toTrim;
}

int_least32_t trimText(char *text) {
    int_least32_t trimmed = trimRight(text);
    trimmed += trimLeft(text);

    return trimmed;
}

