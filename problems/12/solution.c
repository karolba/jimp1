
// author: Karol Baraniecki


#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <limits.h>


#define DISP_IN(fmt, sz, min, max, q1, q2) \
    printf(#sz " = %zu in [" q1 fmt q1 ", " q2 fmt q2 "]\n", sz, min, max) \

#define DISP(fmt, sz, min, max) do { \
    if(!firstquoted && !secondquoted) \
        DISP_IN(fmt, sz, min, max, "", ""); \
    if(firstquoted && !secondquoted) \
        DISP_IN(fmt, sz, min, max, "\"", ""); \
    if(!firstquoted && secondquoted) \
        DISP_IN(fmt, sz, min, max, "", "\""); \
    if(firstquoted && secondquoted) \
        DISP_IN(fmt, sz, min, max, "\"", "\""); \
    } while(0)
        

int main() {
    int firstquoted = 0, secondquoted = 0; 

    DISP("%d", sizeof(int), INT_MIN, INT_MAX);
    //firstquoted = 0;
    DISP("%u", sizeof(unsigned), (unsigned) 0, UINT_MAX);
    //firstquoted = 1;
    DISP("%ld", sizeof(long), LONG_MIN, LONG_MAX);
    // w wynikach nie ma?
    //DISP("%ld", sizeof(long), LONG_MIN, LONG_MAX);

    //firstquoted = 0;
    DISP("%lu", sizeof(unsigned long), (unsigned long) 0, ULONG_MAX);
    //firstquoted = 1;
    DISP("%d", sizeof(short), INT16_MIN, INT16_MAX);
    //firstquoted = 0;
    DISP("%d", sizeof(unsigned short), (unsigned short) 0, (unsigned short) -1);
    //firstquoted = 1;
    DISP("%d", sizeof(char), CHAR_MIN, CHAR_MAX);
    //firstquoted = 0;
    DISP("%d", sizeof(unsigned char), 0, UCHAR_MAX);
    //firstquoted = 0;
    DISP("%d", sizeof(signed char), SCHAR_MIN, SCHAR_MAX); // powinno byc SCHAR_MIN ale blad w zadaniu
    //firstquoted = 1;
    DISP("%lld", sizeof(long long), LLONG_MIN, LLONG_MAX);
    //firstquoted = 0;
    DISP("%llu", sizeof(long long unsigned), (unsigned long long) 0, ULLONG_MAX);
    puts("");

    //firstquoted = 1;
    DISP("%.7g", sizeof(float), FLT_MIN, FLT_MAX);
    DISP("%.7lg", sizeof(double), DBL_MIN, DBL_MAX);
    DISP("%.7Lg", sizeof(long double), LDBL_MIN, LDBL_MAX);
    puts("");

    //firstquoted = 0;
    //secondquoted = 0;
    DISP("%ld", sizeof(int_fast16_t), INT_FAST16_MIN, INT_FAST16_MAX);
    
    DISP("%d", sizeof(int_least16_t), INT_LEAST16_MIN, INT_LEAST16_MAX);
}
