// author: Karol Baraniecki

#include <stdio.h>

int main() {
    double kg, m;
    scanf("%lf", &kg);
    scanf("%lf", &m);

    printf("%.2lf\n", kg / (m * m));

    return 0;
}
