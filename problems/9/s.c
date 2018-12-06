// author: Karol Baraniecki

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

static bool isFact(int64_t n) {
    int64_t i = 1, fact = 1;
    while(fact < n) {
        fact *= i;
        i++;
    }

    return fact == n;
} 

static bool isPrime(int64_t n) {
    if(n < 2)
        return false;

    for(int64_t i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

static void divisors(int64_t n) {
    printf("divisors: ");

    for(int64_t i = 2; i < n; i++) {
        if(n % i == 0)
            printf("%ld,", i);
    }

    puts("");
}

static bool isFib(int64_t n) {
    int64_t t1 = 0, t2 = 1, next;
    while(t1 < n) {
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }

    return t1 == n;
}

static int64_t magnitude(int64_t n) {
    int64_t mag = 1;
    while(n >= mag)
        mag *= 10;
    return mag;
}

static bool isAutomorphic(int64_t n) {
    if(n <= 0)
        return false;

    int64_t sq = n * n;
    return n == sq % magnitude(n);
}

int main() {
    int64_t number;

    int ret = scanf("%ld", &number);

    if(ret == 0) {
        puts("Nothing read!");
        return 0;
    } else if(ret < 0) {
        puts("Error while reading");
        return 0;
    }

    printf("%ld = 0%lo = 0x%lx\n", number, number, number);

    if(isPrime(number))
        puts("prime number");
    else if(number > 2)
        divisors(number);

    if(isFact(number) && number != 2) // błąd w zadaniu?
        puts("factorial number");

    if(isFib(number))
        puts("fibonacci number");

    if(isAutomorphic(number))
        puts("automorphic number");


    return 0;
}
