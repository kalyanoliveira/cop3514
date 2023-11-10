/*
 * The code for reversing an array.
 */

#include <stdio.h>

#define N 11

int main(void)
{
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int buffer;

    // We need to use N / 2.
    // Else we just keep swapping number even after reaching the middle of the
    // array.
    for (int i = 0; i < N / 2; i++)
    {
        // This is essentially a swap algorithm.
        // temp = x
        // x = y
        // y = temp
        buffer = a[(N - 1) - i];
        a[(N - 1) - i] = a[i];
        a[i] = buffer;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
