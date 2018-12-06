// author: Karol Baraniecki

#include <stdio.h>
#include <errno.h>
//#include "factorian.h"
#include <stdint.h>

#define T int_fast64_t

enum FactorianErrors
{
    FACTORIAN_ERROR_NEGATIVE_VALUE = -1,
    FACTORIAN_TOO_GREAT_VALUE = -2
};


T factorian(T a) {
    if(a < 0) {
        errno = FACTORIAN_ERROR_NEGATIVE_VALUE;
        return -1;
    }
    T prod = 1;
    for(int i = 1; i <= a; i++) {
        prod *= i;
        if(prod < 0) {
            errno = FACTORIAN_TOO_GREAT_VALUE;
            return -1;
        }
    }
    
    return prod;
}
