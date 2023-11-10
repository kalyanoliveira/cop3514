#include <stdio.h>

int main(void)
{
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    
    int original = i;
    
    int j = 0;

    do
    {
        i /= 10;
        j++;
    }
    while (i != 0);

    printf("The number of digits in %d is %d", original, j);

    return 0;
}
