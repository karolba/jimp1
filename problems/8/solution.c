// author: Karol Baraniecki

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define F_SQUARE 1
#define F_CIRCLE 2
#define F_TRIANGLE 3
#define F_RECTANGLE 4

static const char *names[] = {NULL, "Square:", "Circle:", "Triangle:", "Rectangle:"};

static void assert_something_read(bool asserted) {
    if(!asserted) {
        puts("Nothing read!");
        exit(0);
    }
}

int main() {
    int figure;
    double in1 = 1, in2 = 1;

    assert_something_read(scanf("%d", &figure) == 1);

    if(figure < F_SQUARE || figure > F_RECTANGLE) {
        puts("Choose out of range!");
        return 0;
    }

    if(figure == F_TRIANGLE || figure == F_RECTANGLE) {
        assert_something_read(scanf("%lf %lf", &in1, &in2) == 2);
    } else {
        assert_something_read(scanf("%lf", &in1) == 1);
    }

    if(in1 <= 0 || in2 <= 0) {
        puts("Read value not greater than zero!");
        return 0;
    }

    puts(names[figure]);

    double area, perimeter;

    if(figure == F_SQUARE) {
        area = in1 * in1;
        perimeter = 4 * in1;
    } else if(figure == F_CIRCLE) {
        area = M_PI * in1 * in1;
        perimeter = 2. * M_PI * in1;
    } else if(figure == F_TRIANGLE) {
        area = .5 * in1 * in2;
        perimeter = in1 + in2 + hypot(in1, in2);
    } else if(figure == F_RECTANGLE) {
        area = in1 * in2;
        perimeter = 2 * (in1 + in2);
    }

    printf("area = %.2lf\n", area);
    printf("perimeter = %.2lf\n", perimeter);

    return 0;
}
