#include <stdio.h>
//author: Piotr Krzesniak
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

static void assert_read(bool asserted)
{
    if(!asserted)
    {
        puts("Nothing read!");
        exit(0);
    }
}
bool prime(int num)
{
    if(num<2)
    {
        return false;
    }
    for(int i=2; i<num; i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
void divisors(int num)
{
    printf("divisors: ");
    for(int i=2; i<num; i++)
    {
        if(num%i==0)
        {
            printf("%d,", i);
        }
    }
    printf("\n");
}
bool factorial(int num)
{
    if(num==0) return true;
    int wynik=1;
    for(int i=1; i<8; i++)
    {
        wynik*=i;
        if (num==wynik)
        {
            return true;
        }
    }
    return false;
}
bool fibonacci(int num)
{
    int tablica[50];
    tablica[0]=1;
    tablica[1]=1;
    if(num==1 || num ==0) return true;
    for(int i=2; i<50; i++)
    {
        tablica[i]=tablica[i-1]+tablica[i-2];
        if (tablica[i]==num)
        {
            return true;
        }
    }
    return false;
}
bool automorphic(int num)
{
    int wynik, modulo=1;
    int power=num*num;
    int length=log10(num)+1;
    for (int i=1; i<=length; i++)
    {
        modulo*=10;
    }
    wynik = power%modulo;
    if(wynik==num)
    {
        return true;
    }
    return false;
}

int main()
{
    int64_t num;
    assert_read(scanf("%Ld", &num));
    printf("%d = 0%Lo =  0x%Lx\n", num, num,num );
    if(prime(num)==true)
    {
        printf("prime number\n");
    }
    if((prime(num)==false) && num > 1 )
    {
        divisors(num);
    }
    if(factorial(num)==true)
    {
        printf("factorial number\n");
    }
    if(fibonacci(num)==true)
    {
        printf("fibonacci number\n");
    }
    if(automorphic(num)==true)
    {
        printf("automorphic number\n");
    }
    return 0;
}
