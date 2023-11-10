#include <stdio.h>

int main(void)
{
    long i;
    long k;
    int j = 1000000;

    //i = j * (long) j;
    k = (long) j * j;

    printf("%ld\n", k);

    return 0;
}   
