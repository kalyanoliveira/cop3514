#include <stdio.h>

int main(void)
{
    // Make sure that the interval of i is [0, 5].
    int i;

    do
    {
        printf("Enter a number [0, 5]: ");
        scanf("%d", &i);
    }
    while (i < 0 || i > 5);

    printf("%d\n", i);
 }
