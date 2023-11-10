#include <stdio.h>

int main(void)
{
    int i;
    printf("Enter a number [0, 5]: ");
    scanf("%d", &i);
    
    // Make sure that the interval of i is [0, 5].
    while (i < 0 || i > 5)
    {
        printf("Enter a number [0, 5]: ");
        scanf("%d", &i);
    }

    printf("%d\n", i);
}
