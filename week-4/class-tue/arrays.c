#include <stdio.h>

#define N 10

int main(void)
{
    // This is how you declare.
    // int a[N];

    // This would be an initialization.
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
