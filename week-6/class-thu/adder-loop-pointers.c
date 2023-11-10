#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};

    int sum = 0;

    // The nuance here is that we have to use the condition of p < &a[5].
    // Index 5 is not part of a. Hence, once we reach that index (or that
    // address, via the [] operator on the array a), we will not execute the
    // loop (because p will be equal to &a[5], and not less than &a[5])
    for (int *p = &a[0]; p < &a[5]; p++)
    {
        sum += *p;
    }

    printf("%d\n", sum);
    
    return 0;
}
