// author: Karol Baraniecki

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/param.h>

#define T int_fast64_t
#define PRI PRIdFAST64
#define SCN SCNdFAST64

T sum(T *arr, size_t len) {
    T s = 0;
    for(size_t i = 0; i < len; i++) {
        s += arr[i];
    }
    return s;
}

double average(T *arr, size_t len) {
    if(len == 0)
        return 0.0;
    return 1. * sum(arr, len) / len;
}

long double median(T *arr, size_t len) {
    if(len == 0)
        return 0.0;

    if(len % 2 == 1)
        return arr[len / 2];
    else
        return (arr[len / 2] + arr[(len - 1) / 2]) / 2.0;
}

int comp(const void *elem1, const void *elem2) 
{
    T *f = (T *)elem1;
    T *s = (T *)elem2;
    if(*f < *s)
        return -1;
    if(*f > *s)
        return 1;
    return 0;
}

int T_decimal_len(T value) {
    int len = 1;
    while(value > 9) {
        len++;
        value /= 10;
    }
    return len;
}

int main() {
    T n;
    if(scanf("%" SCN, &n) != 1)
        n = 0;
    scanf("%*[^\n]");

    if(n < 0)
        n = 0;

    n = MIN(n, 16384);

    T *arr = malloc(n * sizeof(T));
    ssize_t j = 0;
    for(ssize_t i = 0; i < n; i++) {
        T in;
        if(scanf("%" SCN, &in) != 1)
            continue;
        arr[j++] = in;
    }

    qsort(arr, n, sizeof(T), comp);

    printf("sum = %" PRI ",\n", sum(arr, n));
    printf("average = %lg,\n", average(arr, n));
    printf("median = %llg,\n", median(arr, n));
    printf("of %" PRI " numbers:\n", n);

    int max_len = T_decimal_len(n);
    for(int i = 0; i < n; i++) {
        printf("%-*d: %" PRI "\n", max_len, i + 1, arr[i]);
    }

    free(arr);
    
    return 0;
}
