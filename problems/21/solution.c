// author: Karol Baraniecki

#include <stdio.h>

int main() {
    int nums[1024 * 1024 / 8];;

    double avg = 0;
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        if(scanf("%d", &num) != 1) {
            break;
        }
        avg += (num - avg) * 1. / (i + 1);
        nums[i] = num;
    }
    printf("average = %g, numbers:\n", avg);
    for(int i = 0; i < n; i++) {
        if((nums[i] % 2) != 0)
            printf("%d\n", nums[i]);
    }
    return 0;
}
