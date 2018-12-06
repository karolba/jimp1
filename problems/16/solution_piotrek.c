#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//author: Piotr Krzesniak

static void assert_read(bool asserted)
{
    if(!asserted)
    {
        puts("Impossible to read!");
        exit(0);
    }
}
void divide(int num1, int num2)
{
    int max=num1;
    if(num2>num1) max=num2;
    int NWD=1;
    for(int i=2; i<max; i++)
    {
        if(num1%i==0 && num2%i==0)
        {
            NWD=i;
        }
    }
    printf("GCD(%d, %d) = %d\n", num1, num2, NWD);
}
int main()
{
    int n;
    if(n<0) printf("One of argument is less or equal 0!");
    int num1, num2;
    assert_read(scanf("%d", &n));
    for(int i=0; i<n; i++)
    {
        assert_read(scanf("%d %d", &num1, &num2) == 2);
        if(num1 <=0 || num2 <=0 )
        {
          printf("One of argument is less or equal 0!");
          exit(0);
        }
        divide(num1, num2);

    }
    return 0;
}
