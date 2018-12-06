// author: Karol Baraniecki

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(unsigned) = %zu\n", sizeof(unsigned));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(long long) = %zu\n", sizeof(long long));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("INT_MAX = %+d\n", INT_MAX);
    printf("INT_MIN = %+d\n", INT_MIN);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("DBL_MIN = %.7g\n", DBL_MIN);
    printf("DBL_MAX = %.7g\n", DBL_MAX);
    printf("DBL_MAX = %f\n", DBL_MAX);

    return 0;
}
