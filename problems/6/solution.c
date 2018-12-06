// author: Karol Baraniecki

#include <stdio.h>

#define K_TO_C(d) ((d) - 273.15)
#define F_TO_C(d) (((d) - 32.) / 1.8)

#define C_TO_F(d) ((d) * 1.8 + 32.0)
#define C_TO_K(d) ((d) + 273.15)

int main() {
    float in;
    scanf("%f", &in);

    printf("%.2fC = %.2fF = %.2fK\n", in, C_TO_F(in), C_TO_K(in));
    printf("%.2fF = %.2fC = %.2fK\n", in, F_TO_C(in), C_TO_K(F_TO_C(in)));
    printf("%.2fK = %.2fC = %.2fF\n", in, K_TO_C(in), C_TO_F(K_TO_C(in)));
    return 0;
}
