// author: Karol Baraniecki

#include <stdio.h>
#include <math.h>

int main() {
    float cnt = 0;

    puts("0");

    char op;
    float i;
    while(scanf(" %c %f", &op, &i) == 2) {
        if(op == '+') cnt += i;
        if(op == '-') cnt -= i;
        if(op == '*') cnt *= i;
        if(op == '/') cnt /= i;


        // ???????????????????????????
        if(cnt > 10) {
            printf("%d\n", (int)cnt);
        } else {
            printf("%g\n", cnt);
        }
    }
    
    return 0;
}
