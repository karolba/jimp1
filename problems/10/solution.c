// author: Karol Baraniecki

#include <stdio.h>

int main() {
	int d;
	scanf("%d", &d);

	printf("%d\n", d);
	printf("%o\n", d);
	printf("%x\n", d);
	printf("%10d\n", d);

	printf("%+d\n", d);
	printf("%-10d\n", d);

	printf("% d\n", d);
    if(d == 0)
        printf("%d = %o = %x\n", d, d, d);
    else
        printf("%d = 0%o = 0x%x\n", d, d, d);
	printf("\"%-+5d\"\n", d);

	return 0;
}
