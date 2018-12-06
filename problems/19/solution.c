// author: Karol Baraniecki

#include <stdio.h>

static void run(int a, int b) {
    if(a < 0)
        a = 0;
    if(b > 255)
        b = 255;    

    for(; a <= b; a++) {
        printf("%d = >>%c<<\n", a, (char)a);
    }
}

int main() {
    int a, b;
    if(scanf("[%d, %d]", &a, &b) != 2)
        return 0;

    if(a > b)
        run(b, a);
    else
        run(a, b);

    return 0;
}
