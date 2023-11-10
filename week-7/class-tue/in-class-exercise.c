#include <stdio.h>

int duplicate(int *a, int size);

int main(void)
{
    int a[] = {1, 2, 3, 2, 3, 4};
    int size = 6; 

    int returned = duplicate(a, size);
    
    printf("%d\n", returned);

    return 0;
}

int duplicate(int *a, int size)
{
    // For each element in the array.
    for (int *p = a; p < a + size; p++)
    {
        // Compare it with every other element. 
        for (int *q = p + 1; q < a + size; q++)
        {
            if (*q == *p) return 1;
        }
    }

    return 0;
}
