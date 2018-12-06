// author: Karol Baraniecki

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

static void assrt(bool a, const char *s) {
    if(!a) {
        puts(s);
        exit(0);
    }
}

int main() {
    int n;
    assrt(scanf("%d", &n) == 1, "Impossible to read!");

    for(int i = 0; i < n; i++) {
        int a, b;
        assrt(scanf("%d %d", &a, &b) == 2, "Impossible to read!");
        assrt(a > 0 && b > 0, "One of argument is less or equal 0!");
        printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    
    return 0;
}
