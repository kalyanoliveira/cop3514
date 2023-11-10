/*
 * Displays the printable ASCII characters and their corresponding integer
 * values.
 */

#include <stdio.h>

int main(void)
{
    for (int i = 32; i < 127; i++)
    {
        printf("%c %d\n", i, i);
    }
    return 0;
}
