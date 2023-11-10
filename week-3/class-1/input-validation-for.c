#include <stdio.h>

int main(void)
{
    int i;
    printf("Enter a number [0, 5]: ");
    scanf("%d", &i);

    // Basically an infinite loop.
    for (;;)
    {
        if (i < 0 || i > 5)
        {
            printf("Enter a number [0, 5]: ");
            scanf("%d", &i);
            continue;
        }
        break; 
    }
    
    printf("The number is %d.\n", i);
}
