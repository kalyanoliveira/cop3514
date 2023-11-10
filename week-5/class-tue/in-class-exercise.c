#include <stdio.h>

int main(void)
{
    // Value declarations
    int i = 4;
    int j = 6;

    // Pointer declarations
    int *p = &i;
    int *q = &j;

    // Printing value and pointers of i
    printf("Printing \"i\" stuff: \n");
    printf("%d %d\n", i, *p);
    printf("%p %p\n", &i, p);

    // Changing i
    *p = 32;

    // Showing updated values of i
    printf("We have now changed the value of i to 32\n");
    printf("%d %d\n", i, *p);

    // Array addresses
    printf("Displaying array stuff: \n");

    int arr[4] = {5, 8, 2, 9};

    for (int k = 0; k < 4; k++)
    {
        printf("%p\n", &arr[k]);
    }
    
    return 0;
}
