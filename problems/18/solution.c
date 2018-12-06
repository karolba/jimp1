// author: Karol Baraniecki

#include <stdio.h>
#include <math.h>


int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == 0) {
        puts("a can't be 0!");
        return 0;
    }

    printf("%gx2%+gx%+g = 0\n", a, b, c);

    double delta = (b * b) - (4 * a * c);

    printf("delta = %.4lf\n", delta);

    if(delta < 0) {
        puts("No roots in real numbers!");
    } else if(delta == 0) {
        double x = (-b) / (2 * a);
        printf("single root: %.4lf\n", x);
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        
        printf("two roots: %.4lf and %.4lf\n", x1, x2);
    }

    return 0;
}
